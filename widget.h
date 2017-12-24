#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "balls.h"
#include <QTimer>
#include <QPaintEvent>
#include <QMouseEvent>


namespace Ui {
    class Widget;
}

const int NUM = 5;

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    QList <Ball> balls;
    QList <Ball>::iterator biter;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void mousePressEvent(QMouseEvent *m);
    void paintEvent(QPaintEvent * e);
protected slots:
    void moveAll();
    void ifClicked();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    bool started;
    Ui::Widget *ui;
};
#endif
