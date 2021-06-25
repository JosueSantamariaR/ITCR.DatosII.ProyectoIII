#include "cesearch.h"
#include "ui_cesearch.h"

ceSearch::ceSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ceSearch)
{
    ui->setupUi(this);
}

ceSearch::~ceSearch()
{
    delete ui;
}
