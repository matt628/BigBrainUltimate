#include "gameresult.h"
#include "ui_gameresult.h"
#include "startwindow.h"

GameResult::GameResult(QWidget *parent, QString time) :
    QDialog(parent),
    ui(new Ui::GameResult)
{
    ui->setupUi(this);
    printData(time);
}

GameResult::~GameResult()
{
    delete ui;
}



void GameResult::on_pushButton_clicked()
{
    this->close();
    StartWindow* pStartWindow = qobject_cast<StartWindow*>(this->parent()->parent());
    if (pStartWindow)
           pStartWindow->restartGame();
}

void GameResult::on_pushButton_2_clicked()
{
    this->close();
    StartWindow* pStartWindow = qobject_cast<StartWindow*>(this->parent()->parent());
    if (pStartWindow)
           pStartWindow->closeGame();

}

void GameResult::printData(QString time)
{
    ui->gameFinishdTime->setText(QString("Your awsome time: ").append(time));

}
