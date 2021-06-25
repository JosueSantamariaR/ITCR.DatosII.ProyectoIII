#include "cerobot.h"
#include "ui_cerobot.h"

ceRobot::ceRobot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ceRobot)
{
    ui->setupUi(this);
}

ceRobot::~ceRobot()
{
    delete ui;
}

void ceRobot::on_pushButton_clicked()
{
    QString filename= QFileDialog::getOpenFileName(
            this,
            "Buscar archvios",
            "/home/santa/Documentos",
            "Text Files (*.text);;All Files (*.*)");
    if(!filename.isEmpty())
    {
        QFile file(filename);
        if(file.open(QFile::ReadOnly)){
            //Aqui se pondria la inserciòn a los discos
        }
        else{
            QMessageBox::warning(this, "Buscador de archivos",tr("Error"));

        }
    }

}


