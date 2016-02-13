#ifndef GLOBALS_H
#define GLOBALS_H

#define FORK_NUM 5
#define DINNERS_NUM 20
#define MAX_SEC 10

#include <QWaitCondition>
#include <QMutex>

extern QWaitCondition g_cv;
extern QMutex g_mutex;


extern int g_counter;

#endif // GLOBALS_H
