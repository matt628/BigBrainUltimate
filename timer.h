#ifndef TIMER_H
#define TIMER_H
#include <QTime>

class Timer
{
public:
    Timer();
    QString getTime();
private:
    QTime time;
};

#endif // TIMER_H
