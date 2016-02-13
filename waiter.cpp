#include "waiter.h"

QVector<bool> Waiter::forks(FORK_NUM, true);

Waiter::Waiter(QObject *parent) :
    QThread(parent)
{
}

void Waiter::run(){
    qDebug()<<"Waiter wakes up";

    g_mutex.lock();
   // while(g_counter<2){
    //    g_mutex.unlock();
      //  sleep(1);
      //  g_mutex.lock();
   // }
   // g_cv.wakeAll();
    g_mutex.unlock();
    return;
}

bool Waiter::hungryRequest(const int &lfork, const int &rfork){
    g_mutex.lock();
    bool answer = forks[lfork] && forks[rfork%forks.size()];
    if(answer){
        forks[lfork] = false;
        forks[rfork%forks.size()] = false;
    }
    g_mutex.unlock();
    return answer;
}

void Waiter::finishRequest(const int &lfork, const int &rfork){
    g_mutex.lock();
    forks[lfork] = true;
    forks[rfork%forks.size()] = true;
    g_cv.wakeAll();
    g_mutex.unlock();
    return;
}
