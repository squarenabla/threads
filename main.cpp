#include <QCoreApplication>
#include <QDebug>

#include <QWaitCondition>

//#include "globals.h"
#include "threadworker.h"
#include "waiter.h"


ThreadWorker philosophers [FORK_NUM];

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //qDebug()<< g_i;


//    ThreadWorker trd(0,0);

//    ThreadWorker trd2(0,1);

     //ThreadWorker::QWaitCondition *cv = new QWaitCondition();


//    trd.start();
//    trd2.start();

    Waiter waiter;
    waiter.start();

    for(int i=0; i<FORK_NUM; ++i){
        philosophers[i].setID(i);
//        trd.setCondition(cv);
        philosophers[i].start();
    }


    //ThreadWorker::cv->wakeAll();

    return a.exec();
}
