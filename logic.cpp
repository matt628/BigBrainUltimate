#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "logic.h"
#include <QTime>
#define STR_EQUAL 0

Logic::Logic(const int points_to_win_)
{
    generatePair();
    POINTS_TO_WIN = points_to_win_;
}



void Logic::updatePoints(bool correctAnswer)
{
    if(correctAnswer)
        points += GOOD_ANSWER_POINTS;
    else
        points -= BAD_ANSWER_POINTS;
}

QString Logic::colorToString(Color color)
{

    switch (color) {
    case red:
        return QString("red");
    case blue:
        return QString("blue");
    case black:
        return QString("black");
    }
    return QString("");
}

bool Logic::isSameColor()
{
 switch (currentColor){
 case red:
     if( QString::compare(currentColorText, "red",  Qt::CaseInsensitive) == STR_EQUAL) return true;
 case blue:
     if( QString::compare(currentColorText, "blue",  Qt::CaseInsensitive) == STR_EQUAL) return true;
 case black:
     if( QString::compare(currentColorText, "black",  Qt::CaseInsensitive) == STR_EQUAL) return true;
 }
 return false;
}

void Logic::generatePair()
{
    srand (time(NULL));
    currentColor = Color(randomInt(SIZE_COLORS));
    currentColorText = colorToString(Color(randomInt(SIZE_COLORS)));

}

QString Logic::generateStyleString(Color color)
{
    return QString("QLabel {color :")
            .append(colorToString(color))
            .append("; }");
}

QString Logic::generateStyleString(QString color)
{
    return QString("QLabel {color :")
            .append(color)
            .append("; }");
}

QString Logic::getRandomColorString()
{
    srand(time(NULL));
    return colorToString(Color(randomInt(SIZE_COLORS)));
}

int Logic::randomInt(int ceilExlusive)
{
    return rand() % ceilExlusive;
}
