#ifndef THREADWORKER_H
#define THREADWORKER_H

#include <QThread>
#include <QWaitCondition>
#include <QMutex>

#include <QDebug>

#include "globals.h"

class ThreadWorker : public QThread
{
    Q_OBJECT
public:
    explicit ThreadWorker(QObject *parent = 0, const int &_id = 0);
    void run();
   // void setCondition(QWaitCondition *_cv);
    static QWaitCondition *cv;
signals:

public slots:


private:
    quint32 id;
    QMutex mutex;
};

#endif // THREADWORKER_H
