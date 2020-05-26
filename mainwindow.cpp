#include<QKeyEvent>
#include<QDateTime>
#include <string>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameresult.h"
#include "ui_gameresult.h"
#include "logic.h"



MainWindow::MainWindow(QWidget *parent, Logic *logic_)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logic = logic_;
    refreshPairs();
    timer = Timer();
    createTimeUpdater();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    ui->time->setText(QString("Time: ")
                      .append(timer.getTime()));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
      if(event->key()== Qt::Key_Right){
            logic->updatePoints(logic->isSameColor());
            printPoints();
      } else if(event->key()== Qt::Key_Left) {
          logic->updatePoints(!logic->isSameColor());
          printPoints();

      } else  {
        QMainWindow::keyPressEvent(event);
      }
      refreshPairs();
}

void MainWindow::refreshPairs()
{
    maybeGameEnd();
    //PAIRS
    logic->generatePair();
    //onlyColor label set
    ui->onlyColor->setText(logic->getRandomColorString());
    QString styleStringColor = logic->generateStyleString(logic->getCurrentColor());
    ui->onlyColor->setStyleSheet(styleStringColor);
    //onlyText label set
    ui->onlText->setText(logic->getCurrentColorText());
    ui->onlText->setStyleSheet(logic->generateStyleString(logic->getRandomColorString()));
}

void MainWindow::printPoints()
{
    this->ui->points->setText(
                QString("Points: ")
                .append(QString::number(logic->getPoints()))
                );
}

void MainWindow::createTimeUpdater()
{
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    updateTimer->start(10); //update every 10 miliseconds
}

void MainWindow::maybeGameEnd()
{
    if(logic->getPoints() >= logic->getPointsToWin()){
        GameResult* gameResult = new GameResult(this, timer.getTime());
        //gameResult->gameFinishdTime; //PRINT TIME HERE
        gameResult->setModal(true);
        gameResult->exec();
    }
}
