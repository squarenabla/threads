#ifndef WAITER_H
#define WAITER_H

#include <QThread>
#include <QDebug>

#include "globals.h"

class Waiter : public QThread
{
    Q_OBJECT
public:
    explicit Waiter(QObject *parent = 0);
    void run();
signals:

public slots:

};

#endif // WAITER_H
