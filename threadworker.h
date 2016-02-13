#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QThread>
#include <QWaitCondition>
#include <QMutex>

#include <QDebug>

#include "globals.h"
#include "waiter.h"

class ThreadWorker : public QThread
{
    Q_OBJECT
public:
    explicit ThreadWorker(QObject *parent = 0, const int &_id = 0);
    void run();
    void setID(const quint32 &_id);
   // void setCondition(QWaitCondition *_cv);
    static QWaitCondition *cv;
signals:
    void statusChanged(const quint16 &id, const QString str);
public slots:


private:
    void p_think();
    void p_eat();

    quint32 id;
    QMutex mutex;

};

#endif // THREADWORKER_H
