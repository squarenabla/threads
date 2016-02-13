#include <QCoreApplication>
#include <QObject>
#include <QDebug>

#include <QWaitCondition>

//#include "globals.h"
#include "threadworker.h"
#include "waiter.h"


ThreadWorker philosophers [FORK_NUM];

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   // qDebug() << QProcessEnvironment::systemEnvironment().contains("TERM");

    Waiter waiter;
    waiter.start();

    for(int i=0; i<FORK_NUM; ++i){
        philosophers[i].setID(i);
        QObject::connect(&philosophers[i], SIGNAL(statusChanged(quint16,QString)),
                         &waiter, SLOT(changeStatus(quint16,QString)));
//        trd.setCondition(cv);
        philosophers[i].start();
    }


    //ThreadWorker::cv->wakeAll();

    return a.exec();
}
