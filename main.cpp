#include <QCoreApplication>
#include <QDebug>

#include <QWaitCondition>

//#include "globals.h"
#include "threadworker.h"





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<< g_i;


    ThreadWorker trd(NULL,0);

    ThreadWorker trd2(NULL,1);

     //ThreadWorker::QWaitCondition *cv = new QWaitCondition();


    trd.start();
    trd2.start();

//    for(int i=0; i<10; ++i){
//        ThreadWorker trd(NULL,i);
//        trd.setCondition(cv);
//        trd.start();
//    }
    g_cv.wakeAll();

    return a.exec();
}
