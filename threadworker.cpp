#include "threadworker.h"

QWaitCondition* ThreadWorker::cv = new QWaitCondition();



ThreadWorker::ThreadWorker(QObject *parent, const int &_id) :
    QThread(parent)
{
    id = _id;
}

void ThreadWorker::setID(const quint32 &_id){
    id = _id;
    return;
}

//void ThreadWorker::setCondition(QWaitCondition *_cv) {
//    cv = _cv;
//    return;
//}

void ThreadWorker::run(){
    //qDebug()<<"Worker "<<id<<" locks";
    //forever{
//        g_mutex.lock();
//        g_counter++;
//        g_cv.wait(&g_mutex);
//        g_counter--;
//        g_mutex.unlock();

//        for(int i=0; i<1000; ++i)
//            qDebug()<<id<<" "<<i;
    //}
    for(int i=0; i<DINNERS_NUM; ++i){
        p_think();
        while(!Waiter::hungryRequest(id, id+1)){
            g_mutex.lock();
            g_cv.wait(&g_mutex);
            g_mutex.unlock();
        }
        p_eat();
        Waiter::finishRequest(id, id+1);
    }
    return;
}

void ThreadWorker::p_think(){
    qDebug()<<"Philosopher "<<id<<" thinks";
    qsrand((uint)id);
    sleep(qrand()%MAX_SEC);
}

void ThreadWorker::p_eat(){
    qDebug()<<"Philosopher "<<id<<" eats";
    qsrand((uint)id);
    sleep(qrand()%MAX_SEC);
}
