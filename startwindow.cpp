#include "startwindow.h"
#include "ui_startwindow.h"
#include "logic.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/imgs/background2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::closeGame()
{
    mainGame->close();
    this->raise();
}

void StartWindow::restartGame()
{
    mainGame->close();
    startGame();
}

void StartWindow::startGame()
{
    Logic * l = new Logic( ui->spinBox_points->value());
    mainGame = new MainWindow(this, l);
    mainGame->show();
}

void StartWindow::on_pushButton_clicked()
{
    startGame();
}

void StartWindow::on_pushButton_2_clicked()
{
    close();
    qApp->quit();
}
