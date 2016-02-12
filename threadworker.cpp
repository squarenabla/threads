#include "threadworker.h"

ThreadWorker::QWaitCondition *cv = new QWaitCondition();

ThreadWorker::ThreadWorker(QObject *parent, const int &_id) :
    QThread(parent)
{
    id = _id;
}

//void ThreadWorker::setCondition(QWaitCondition *_cv) {
//    cv = _cv;
//    return;
//}

void ThreadWorker::run(){
    //forever{
        mutex.lock();

        cv->wait(&mutex);
        for(int i=0; i<1000; ++i)
            qDebug()<<id<<" "<<i;
        mutex.unlock();
    //}
    return;
}
