#include "nivel1.h"
#include "ui_nivel1.h"
#include "win1.h"
//#include <QFontDatabase>

// *** back end ***
#include <QDebug>

// *** back end ***

Nivel1::Nivel1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel1)
{
    ui->setupUi(this);
    // set music
//    music1 = new QMediaPlayer();
//    music1->setMedia(QUrl("qrc:/audio/Good Starts.mp3"));
//    music1->play();

    // set background gif
    movie = new QMovie(":/gifs/gifs/bg1.gif");
    ui->bg1->setMovie(movie);
    movie->start();

    // set title's typography
    QFont audiowide = QFont("Audiowide",tamletra,1);
    ui->label->setFont(audiowide);
//    QFontDatabase::addApplicationFont(":/fonts/fonts/AirbagFree-Regular.ttf");
//    QFont titlefont = QFont("AirbagFree",tamletra,1);
//    ui->title->setFont(titlefont);

    // connect the win1's clicked signal with the destructor of this window
    connect(win1,SIGNAL(clicked()),this,SLOT(cerrar()));


    // ***************** back end *********************

    h_limit=1000;                   //Asigna los valores leidos el archivo
    v_limit=500;
    dt=0.02;                            //Asigna el lapso de tiempo

    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->addRect(scene->sceneRect());


    //rectangle=scene->addRect(-100,-100,0.5,100,blackpen,blueBrush);
    //rectangle=scene->addRect(500,50,0,100,QPen(Qt::black),QBrush(Qt::red));
    // Obstáculos
    rectangles.append(scene->addRect(200,50,0,200,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(800,50,0,200,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(300,300,0,200,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(700,300,0,200,QPen(Qt::black),QBrush(Qt::red)));

    timer->stop();                              //para el timer



    //---------------------------------------------------------------//
    // Variables físicas para el MCU
    timer->start(1000*dt);
    srand(time(NULL));
    float px=0,py=0,radio=0,vx=0,vy=0,masa=0;
    px=800;
    py=100;
    radio=10;
    vx=200; //velocidad angular
    vy=0; //aceleracion angular
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
    parabolico->getEsf()->setVel(0,100);
    scene->addItem(parabolico);
    //---------------------------------------------------------------//


    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    for(int i=0;i<bars.size();i++){
        bars.at(i)->actualizar(dt,v_limit);
    }
    // ****************** back end ********************
}


Nivel1::~Nivel1()
{
    // *** back end ***
    delete timer;
    delete scene;
    // *** back end ***

    delete ui;
}

void Nivel1::cerrar()
{
    this->close();
}


// ******************************** back end ******************************** //
void Nivel1::actualizar(){
    if(banderacontador==1){
             contador++;
    }

    if(contador==3000){
        timer->stop();
        this->close();
    }
    if(Pressed==true){
        if(tiros<10){

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
        if(tiros>=10){
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
            win1->exec();
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
        bars.at(i)->actualizar(dt,v_limit);

    }


    for(int i=0;i<bars2.size();i++){
        bars2.at(i)->actualizar(dt,v_limit);
    }
}

void Nivel1::bordercollision(EsferaSim *b)
{
    if(b->getX()<b->getR() || b->getX()>h_limit-b->getR()){
        b->setVel(-e*b->getVx(),b->getVy());
    }
    if(b->getY()<b->getR() || b->getY()>v_limit-b->getR()){
     // b->setVel(b->getVx(),-e*b->getVy());
        b->setVel(b->getVx(),-b->getVy());
    }
}

void Nivel1::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space /*&& bandera==0*/)
       {
           Pressed=true;
           bandera=1;

           //tiros++;
       }
}

void Nivel1::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
       {
           Pressed=false;
          // bandera=1;
       }
}

// ******************************** back end ******************************** //
