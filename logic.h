#ifndef LOGIC_H
#define LOGIC_H
#include <QApplication>
#include <QLabel>
#include "Colors.h"
#include "mainwindow.h"
class Logic
{
public:
    Logic(const int points_to_win_);
    void updatePoints(bool correctAnswer);
    QString colorToString(Color color);
    bool isSameColor();
    //random functions
    void generatePair();
    QString generateStyleString(Color color);
    QString generateStyleString(QString color);
    QString getRandomColorString();
    int randomInt(int ceilExlusive);
    //getters
    int getPointsToWin() {return POINTS_TO_WIN; }
    Color getCurrentColor() {return currentColor; }
    QString getCurrentColorText() {return currentColorText; }
    int getPoints() {return points;}
    //setters
private:
    int points = 0;
    Color currentColor;
    QString currentColorText;
    //game coefficients
    size_t POINTS_TO_WIN;
    const size_t GOOD_ANSWER_POINTS = 100;
    const size_t BAD_ANSWER_POINTS = 50;

};

#endif // LOGIC_H
