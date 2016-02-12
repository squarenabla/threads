#include "waiter.h"

Waiter::Waiter(QObject *parent) :
    QThread(parent)
{
}

void Waiter::run(){
    qDebug()<<"Waiter wakes up";

    g_mutex.lock();
    while(g_counter<2){
        g_mutex.unlock();
        sleep(1);
        g_mutex.lock();
    }
    g_cv.wakeAll();
    g_mutex.unlock();
    return;
}
