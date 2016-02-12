#include "threadworker.h"

QWaitCondition* ThreadWorker::cv = new QWaitCondition();

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
    qDebug()<<"Worker "<<id<<" locks";
    //forever{
        g_mutex.lock();
        g_counter++;
        g_cv.wait(&g_mutex);
        g_counter--;
        g_mutex.unlock();

        for(int i=0; i<1000; ++i)
            qDebug()<<id<<" "<<i;
    //}
    return;
}
