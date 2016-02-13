#ifndef WAITER_H
#define WAITER_H

#include <QThread>
#include <QDebug>
#include <QProcess>

#include <QString>

#include "globals.h"

class Waiter : public QThread
{
    Q_OBJECT
public:
    explicit Waiter(QObject *parent = 0);
    void run();
    static bool hungryRequest(const int &lfork, const int &rfork);
    static void finishRequest(const int &lfork, const int &rfork);
signals:

public slots:
    void changeStatus(const quint16 &id, const QString str);
private:
    static QVector<bool> forks;
   // static QMutex mutex;
    static QVector<QString> thinkerStatus;
};

#endif // WAITER_H
