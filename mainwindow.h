#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>

#include "timer.h"
#include "startwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class StartWindow;
class Logic;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Logic* logic_ = nullptr);
    ~MainWindow();
public slots:
    void updateTime();

private:
    Logic* logic;
    Timer timer;
    void keyPressEvent(QKeyEvent *event);
    void refreshPairs();
    void printPoints();
    void createTimeUpdater();
    void maybeGameEnd();
    Ui::MainWindow *ui;
    StartWindow* startWindow;
    QTimer* updateTimer;

};
#endif // MAINWINDOW_H
