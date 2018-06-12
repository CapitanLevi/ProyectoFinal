#include "nivel5.h"
#include "ui_nivel5.h"
#include <QDebug>

Nivel5::Nivel5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel5)
{
    ui->setupUi(this);
    // seet background gif
    movie = new QMovie(":/gifs/gifs/bg5.gif");
    ui->bg5->setMovie(movie);
    movie->start();
    // set typography
    QFont audiowide = QFont("Audiowide",25,1);
    ui->label->setFont(audiowide);
    // ********************** BACK END ************************** //
    h_limit=1000;                   //Asigna los valores leidos el archivo
    v_limit=500;
    dt=0.02;                            //Asigna el lapso de tiempo

    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);
         //   qDebug()<<ui->graphicsView->size();
//    ui->centralWidget->adjustSize();
      //      qDebug()<<ui->centralWidget->size();
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
//   this->adjustSize();//


       // qDebug()<<this->size();
    scene->addRect(scene->sceneRect());


    //rectangle=scene->addRect(-100,-100,0.5,100,blackpen,blueBrush);
    //rectangle=scene->addRect(500,50,0,100,QPen(Qt::black),QBrush(Qt::red));

    rectangles.append(scene->addRect(400,50,0,150,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(800,50,0,150,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(100,100,0,400,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(400,300,0,150,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(700,50,0,400,QPen(Qt::black),QBrush(Qt::red)));
    //rectangles.append(scene->addRect(500,170,0,100,QPen(Qt::black),QBrush(Qt::red)));



    timer->stop();                              //para el timer



    //---------------------------------------------------------------//
    timer->start(1000*dt);
    srand(time(NULL));
    float px=0,py=0,radio=0,vx=0,vy=0,masa=0;
    px=800;
    py=100;
    radio=10;
    vx=150; //velocidad angular
    vy=0.7; //aceleracion angular
    masa=2;
    e=rand()% 1+0.5;

    //bars.append(new EsferaGraf(px,py,radio,masa));
    //bars2.append(new esferasimmovcirgraf(masa,px,py,radio,radio+20,vx/30,-vy/35,v_limit));
    bars2.append(new esferasimmovcirgraf(masa,px,py,radio,radio+20,vx/30,vy,v_limit));
    //bars.last()->getEsf()->setVel(vx,vy);
    //scene->addItem(bars.last());
    scene->addItem(bars2.last());

    //bars.append(new EsferaGraf(20,20,10,masa,v_limit));
    //bars.last()->getEsf()->setVel(0,vy);
    parabolico= new EsferaGraf(20,20,10,masa,v_limit);
    parabolico->getEsf()->setVel(0,60);
    scene->addItem(parabolico);
    //---------------------------------------------------------------//


    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


/*    painter->setBrush(Qt::darkYellow);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect*/

    //obstaculo1->setBrush(Qt::darkGreen);
    //obstaculo1->drawRect(QRect());


    for(int i=0;i<bars.size();i++){
        bars.at(i)->actualizar(dt,v_limit);
    }

}

Nivel5::~Nivel5()
{
    delete timer;
    delete scene;
    delete ui;
}


void Nivel5::actualizar()
{
    if(banderacontador==1){
         contador++;
    }

    if(contador==1000){
        timer->stop();
    }
    if(Pressed==true){
        if(tiros<8){

            float x=bars2.last()->getesfera()->getX();
            float y=bars2.last()->getesfera()->getY();
            float m=10;
            float r=10;
            bars.append(new EsferaGraf(x,y,r,m,v_limit));
            bars.last()->getEsf()->setVel(bars2.last()->getesfera()->getVx(),
                                          bars2.last()->getesfera()->getVy());
            scene->addItem(bars.last());
            tiros++;
        }
        if(tiros>=8){
            banderacontador=1;
        }


    }

    parabolico->actualizar(dt,v_limit);
    bordercollision(parabolico->getEsf());
    //actualizar el escenario

    for(int i=0;i<bars.size();i++){
        bordercollision(bars.at(i)->getEsf());
        if(parabolico->collidesWithItem(bars.at(i))){
            qDebug()<<"estoy dentro"<<endl;
            timer->stop(); //-->descomentarr, importante
            Ganador=1;
        }

        for(int j=0;j<rectangles.size();j++){
            if(bars.at(i)->collidesWithItem(rectangles.at(j))){
                bars.at(i)->getEsf()->setVel(-bars.at(i)->getEsf()->getVx(),
                                             bars.at(i)->getEsf()->getVy());
            }
        }
        /*if(bars.at(i)->collidesWithItem(rectangle)){
            bars.at(i)->getEsf()->setVel(-bars.at(i)->getEsf()->getVx(),
                                         bars.at(i)->getEsf()->getVy());
        }*/
        bars.at(i)->actualizar2(dt,v_limit);

    }


    for(int i=0;i<bars2.size();i++){
        bars2.at(i)->actualizar(dt,v_limit);
    }
}

void Nivel5::bordercollision(EsferaSim *b)
{
    if(b->getX()<b->getR() || b->getX()>h_limit-b->getR()){
        b->setVel(-b->getVx(),b->getVy());
    }
    if(b->getY()<b->getR() || b->getY()>v_limit-b->getR()){
     // b->setVel(b->getVx(),-e*b->getVy());
        b->setVel(b->getVx(),-b->getVy());
    }
}

void Nivel5::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space /*&& bandera==0*/)
       {
           Pressed=true;
           bandera=1;

           //tiros++;
       }
}

void Nivel5::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
       {
           Pressed=false;
          // bandera=1;
       }
}
