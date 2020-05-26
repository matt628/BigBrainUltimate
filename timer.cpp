#include "timer.h"

Timer::Timer()
{
    time.start();
}

QString Timer::getTime()
{
    int time_ms = time.elapsed();
    int ms = time_ms%1000;
    time_ms /= 1000;
    int s = time_ms%60;
    time_ms /= 60;
    int min = time_ms;
    return QString()
            .append(QString::number(min).append("min:"))
            .append(QString::number(s).append("s:"))
            .append(QString::number(ms).append("ms"));
}
