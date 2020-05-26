#ifndef GAMERESULT_H
#define GAMERESULT_H

#include <QDialog>

namespace Ui {
class GameResult;
}

class GameResult : public QDialog
{
    Q_OBJECT

public:
    explicit GameResult(QWidget *parent = nullptr , QString time = "");
    ~GameResult();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void printData(QString time);
    Ui::GameResult *ui;
};

#endif // GAMERESULT_H
