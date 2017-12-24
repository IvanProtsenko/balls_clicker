#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMessageBox>
#include <ctime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(int i = 0; i<5; i++) {
        balls.push_back(Ball(width(), height()));
    }
    started = false;
    connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *m)
{
    int x = m->x();
    int y = m->y();
    for(biter = balls.begin(); biter != balls.end(); biter++) {
        int a = biter->getx();
        int c = biter->gety();
        if((x - a)*(x - a)+(y - c)*(y - c) <= (35)*(35))
        {
            biter = balls.erase(biter);
            balls.push_back(Ball(width(), height()));
            break;
        }
    }
}
void Widget::on_pushButton_2_clicked()
{
    this->close();
}

void Widget::on_pushButton_clicked()
{
    started = true;
}
void Widget::paintEvent(QPaintEvent *e)
{
    if(started) {
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        QPainter painter(this);
        for(biter = balls.begin(); biter != balls.end(); biter++) {
            biter -> draw(painter);
        }
    }
}

void Widget::moveAll()
{
    if(started) {
        for(biter = balls.begin(); biter != balls.end(); biter++) {
            biter -> move(width(), height());
        }
        this->repaint();
    }
}

void Widget::ifClicked()
{

}



