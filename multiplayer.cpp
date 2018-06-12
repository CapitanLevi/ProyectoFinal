#include "multiplayer.h"
#include "ui_multiplayer.h"
#include "menuprincipal.h"
#include "ganadorm.h"
#include "ganadorm2.h"

extern MenuPrincipal *w;

Multiplayer::Multiplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Multiplayer)
{
//    w->music->stop();
//    w->MenuPrincipal::~MenuPrincipal();
    ui->setupUi(this);
    // set background gif
    moviem = new QMovie(":/gifs/gifs/bgm.gif");
    ui->bgm->setMovie(moviem);
    moviem->start();
    // set typography
    QFont audiowide = QFont("Audiowide",tamletra,1);
    ui->label->setFont(audiowide);
    // ************************** BACK END ************************ //
    h_limit=1000;                   //Asigna los valores leidos el archivo
    v_limit=500;
    dt=0.02;                            //Asigna el lapso de tiempo

    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->addRect(scene->sceneRect());
    // Añadiendo obstáculos
    rectangles.append(scene->addRect(100,50,0,100,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(300,70,0,100,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(600,50,0,100,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(900,70,0,100,QPen(Qt::black),QBrush(Qt::red)));


   // rectangles.append(scene->addRect(100,350,0,100,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(300,250,0,100,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(600,350,0,100,QPen(Qt::black),QBrush(Qt::red)));
    rectangles.append(scene->addRect(900,250,0,100,QPen(Qt::black),QBrush(Qt::red)));

    //rectangles.append(scene->addRect(700,50,0,400,QPen(Qt::black),QBrush(Qt::red)));
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
    vy=0.2; //aceleracion angular
    masa=2;
    e=rand()% 1+0.5;

    //bars.append(new EsferaGraf(px,py,radio,masa));
    //bars2.append(new esferasimmovcirgraf(masa,px,py,radio,radio+20,vx/30,-vy/35,v_limit));
    bars2.append(new esferasimmovcirgraf(masa,px,py,radio,radio+20,vx/30-1,vy,v_limit));
    //bars.last()->getEsf()->setVel(vx,vy);
    //scene->addItem(bars.last());
    scene->addItem(bars2.last());

    //bars.append(new EsferaGraf(20,20,10,masa,v_limit));
    //bars.last()->getEsf()->setVel(0,vy);
    parabolico= new EsferaGraf(500,300,10,masa,v_limit);
    parabolico->getEsf()->setVel(0,60);
   // painter->setBrush(Qt::yellow);
   // parabolico->paint(painter);
  //  painter->setBrush(Qt::yellow);
    scene->addItem(parabolico);

    esfera2= new esferasimmovcirgraf(masa,100,100,10,30,vx/30,-vy,v_limit);
    scene->addItem(esfera2);
    //---------------------------------------------------------------//


    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


/*    painter->setBrush(Qt::darkYellow);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect*/

    //obstaculo1->setBrush(Qt::darkGreen);
    //obstaculo1->drawRect(QRect());


    for(int i=0;i<bars.size();i++){
        bars.at(i)->actualizar(dt,v_limit);
    }
    // ************************** BACK END ***************************** //
}

Multiplayer::~Multiplayer()
{
    delete timer;
    delete scene;
    delete ui;
}

// ************************** BACK END ***************************** //

void Multiplayer::actualizar()
{
    if(banderacontador==1){
   //      contador++;
    }


    if(Pressed==true && turno==0){
        if(tiros<8){
            //contador++;
            float x=bars2.last()->getesfera()->getX();
            float y=bars2.last()->getesfera()->getY();
            float m=10;
            float r=10;
            bars.append(new EsferaGraf(x,y,r,m,v_limit));
            bars.last()->getEsf()->setVel(bars2.last()->getesfera()->getVx(),
                                          bars2.last()->getesfera()->getVy());
            /*if(bars.size()>1){
                bars.pop_back();}*/
            scene->addItem(bars.last());
            tiros++;
            turno=1;
        }
        if(tiros>=8){
            banderacontador=1;
        }


    }
    if(Pressed1==true && turno==1){
        if(tiros1<8){

            float x=esfera2->getesfera()->getX();
            float y=esfera2->getesfera()->getY();
            float m=10;
            float r=10;
            barsesfera2.append(new EsferaGraf(x,y,r,m,v_limit));
            barsesfera2.last()->getEsf()->setVel(esfera2->getesfera()->getVx(),
                                          esfera2->getesfera()->getVy());
            scene->addItem(barsesfera2.last());
            tiros1++;
            turno=0;
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
            qDebug()<<"ganador es 1"<<endl;
            GanadorM mensaje;
            mensaje.setModal(true);
            mensaje.exec();
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

    /*------------*/
    for(int i=0;i<barsesfera2.size();i++){
        bordercollision(barsesfera2.at(i)->getEsf());
        if(parabolico->collidesWithItem(barsesfera2.at(i))){
            qDebug()<<"estoy dentro"<<endl;
            timer->stop(); //-->descomentarr, importante
            Ganador=2;
            qDebug()<<"ganador es 2"<<endl;
            GanadorM2 mensaje;
            mensaje.setModal(true);
            mensaje.exec();
        }



        for(int j=0;j<rectangles.size();j++){
            if(barsesfera2.at(i)->collidesWithItem(rectangles.at(j))){
                barsesfera2.at(i)->getEsf()->setVel(-barsesfera2.at(i)->getEsf()->getVx(),
                                             barsesfera2.at(i)->getEsf()->getVy());
            }

        }
        /*if(bars.at(i)->collidesWithItem(rectangle)){
            bars.at(i)->getEsf()->setVel(-bars.at(i)->getEsf()->getVx(),
                                         bars.at(i)->getEsf()->getVy());
        }*/
        barsesfera2.at(i)->actualizar2(dt,v_limit);

    }
    //------------//


    for(int i=0;i<bars2.size();i++){
        bars2.at(i)->actualizar(dt,v_limit);
    }
    esfera2->actualizar(dt,v_limit);
}

void Multiplayer::bordercollision(EsferaSim *b)
{
    if(b->getX()<b->getR() || b->getX()>h_limit-b->getR()){
        b->setVel(-b->getVx(),b->getVy());
    }
    if(b->getY()<b->getR() || b->getY()>v_limit-b->getR()){
     // b->setVel(b->getVx(),-e*b->getVy());
        b->setVel(b->getVx(),-b->getVy());
    }
}







void Multiplayer::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space /*&& bandera==0*/&& turno==0)
       {
           Pressed=true;
           Pressed1=false;
           bandera=1;

           //tiros++;
       }
    else if(event->key()==Qt::Key_R && turno==1)
    {
            Pressed1=true;
            Pressed=false;
    }
}

void Multiplayer::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
       {
           Pressed=false;
          // bandera=1;
       }
}

// ************************* BACK END ************************** //
