#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include "mainwindow.h"
#include <QMainWindow>

class MainWindow;
namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    void closeGame();
    void restartGame();
    void startGame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::StartWindow *ui;
    MainWindow *mainGame;
};

#endif // STARTWINDOW_H
