#ifndef CESEARCH_H
#define CESEARCH_H

#include <QWidget>

namespace Ui {
class ceSearch;
}

class ceSearch : public QWidget
{
    Q_OBJECT

public:
    explicit ceSearch(QWidget *parent = nullptr);
    ~ceSearch();

private:
    Ui::ceSearch *ui;
};

#endif // CESEARCH_H
