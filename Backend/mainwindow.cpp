#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#define RUTA_ARCHIVO "arch.txt"     //ruta en que se encuentra el archivo

int bandera=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QString info;                       //String para leer los datos del archivo

//    QFile file(RUTA_ARCHIVO);           //Objeto para manejar la lectura del archivo
//    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
//    info=file.readLine();

//    QList<QString> dats;
//    int n=0;
//    while(n>=0){      //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo vec
//        n = info.indexOf(" ");
//        if(n!=0){
//            dats.append(info.left(n));
//        }
//        info=info.remove(0,n+1);
//    }
/*    for(int i=0;i<dats.size();i++){
        qDebug()<<dats.at(i);

    }*/

    h_limit=1000;                   //Asigna los valores leidos el archivo
    v_limit=500;
    dt=0.02;                            //Asigna el lapso de tiempo

    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);
         //   qDebug()<<ui->graphicsView->size();
    ui->centralWidget->adjustSize();
      //      qDebug()<<ui->centralWidget->size();
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//   this->adjustSize();//


       // qDebug()<<this->size();
    scene->addRect(scene->sceneRect());


    //rectangle=scene->addRect(-100,-100,0.5,100,blackpen,blueBrush);
    rectangle=scene->addRect(500,50,0,100,QPen(Qt::black),QBrush(Qt::red));
    timer->stop();                              //para el timer
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


/*    painter->setBrush(Qt::darkYellow);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect*/

    //obstaculo1->setBrush(Qt::darkGreen);
    //obstaculo1->drawRect(QRect());


    for(int i=0;i<bars.size();i++){
        bars.at(i)->actualizar(dt,v_limit);
    }

}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{
    if(Pressed==true){
        float x=bars2.last()->getesfera()->getX();
        float y=bars2.last()->getesfera()->getY();
        float m=10;
        float r=10;
        bars.append(new EsferaGraf(x,y,r,m,v_limit));
        bars.last()->getEsf()->setVel(bars2.last()->getesfera()->getVx(),
                                      bars2.last()->getesfera()->getVy());
        scene->addItem(bars.last());

    }

    parabolico->actualizar(dt,v_limit);
    bordercollision(parabolico->getEsf());
    //actualizar el escenario

    for(int i=0;i<bars.size();i++){
        bordercollision(bars.at(i)->getEsf());
        if(parabolico->collidesWithItem(bars.at(i))){
            qDebug()<<"estoy dentro"<<endl;
            timer->stop();
        }
        if(bars.at(i)->collidesWithItem(rectangle)){
            bars.at(i)->getEsf()->setVel(-bars.at(i)->getEsf()->getVx(),
                                         bars.at(i)->getEsf()->getVy());
        }
        bars.at(i)->actualizar(dt,v_limit);

    }


    for(int i=0;i<bars2.size();i++){
        bars2.at(i)->actualizar(dt,v_limit);
    }
}

void MainWindow::bordercollision(EsferaSim *b)
{
    if(b->getX()<b->getR() || b->getX()>h_limit-b->getR()){
        b->setVel(-e*b->getVx(),b->getVy());
    }
    if(b->getY()<b->getR() || b->getY()>v_limit-b->getR()){
     // b->setVel(b->getVx(),-e*b->getVy());
        b->setVel(b->getVx(),-b->getVy());
    }
}

void MainWindow::colision(EsferaGraf *b, EsferaGraf *c)
{
    if(b->collidesWithItem(c)){
      //  qDebug()<<"Hubo coliision"<<endl;
        timer->stop();
    }

}



void MainWindow::on_start_clicked()
{
     timer->start(1000*dt);
}

void MainWindow::on_add_clicked()
{
    srand(time(NULL));
    float px=0,py=0,radio=0,vx=0,vy=0,masa=0;
    px=rand()% 950+50;
    py=rand()% 450+50;
    radio=rand()% 30+5;
    vx=rand()% 300+1;
    vy=rand()% 300+1;
    masa=rand()% 600+50;
    e=rand()% 1+0.5;

    //bars.append(new EsferaGraf(px,py,radio,masa));
    bars2.append(new esferasimmovcirgraf(masa,px,py,radio,radio+20,vx/30,-vy/35,v_limit));
    //bars.last()->getEsf()->setVel(vx,vy);
    //scene->addItem(bars.last());
    scene->addItem(bars2.last());

    //bars.append(new EsferaGraf(20,20,10,masa,v_limit));
    //bars.last()->getEsf()->setVel(0,vy);
    parabolico= new EsferaGraf(20,20,10,masa,v_limit);
    parabolico->getEsf()->setVel(0,vy);
    scene->addItem(parabolico);

}

void MainWindow::on_stop_clicked()
{
    timer->stop();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space /*&& bandera==0*/)
       {
           Pressed=true;
           bandera=1;
       }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
       {
           Pressed=false;
          // bandera=1;
       }
}
