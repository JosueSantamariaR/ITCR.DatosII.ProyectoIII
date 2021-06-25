#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cerobot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   ceRobot *ventanaRB = new ceRobot();
   ventanaRB->show();

}


void MainWindow::on_pushButton_2_clicked()
{
    ceSearch *ventanaSR = new ceSearch();

    ventanaSR->show();

}
