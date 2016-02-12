#ifndef GLOBALS_H
#define GLOBALS_H

#include <QWaitCondition>
#include <QMutex>

extern QWaitCondition g_cv;
extern QMutex g_mutex;


extern int g_counter;

#endif // GLOBALS_H
