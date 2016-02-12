#include <QCoreApplication>
#include <QDebug>

#include <QWaitCondition>

//#include "globals.h"
#include "threadworker.h"
#include "waiter.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //qDebug()<< g_i;


    ThreadWorker trd(0,0);

    ThreadWorker trd2(0,1);

     //ThreadWorker::QWaitCondition *cv = new QWaitCondition();


    trd.start();
    trd2.start();

    Waiter waiter;
//    for(int i=0; i<10; ++i){
//        ThreadWorker trd(NULL,i);
//        trd.setCondition(cv);
//        trd.start();
//    }
    waiter.start();

    //ThreadWorker::cv->wakeAll();

    return a.exec();
}
