#ifndef CEROBOT_H
#define CEROBOT_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
namespace Ui {
class ceRobot;
}

class ceRobot : public QWidget
{
    Q_OBJECT

public:
    explicit ceRobot(QWidget *parent = nullptr);
    ~ceRobot();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ceRobot *ui;
};

#endif // CEROBOT_H
