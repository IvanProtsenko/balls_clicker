#include "balls.h"

Ball::Ball(int w, int h)
{
    r = 35;
    point.setX(r + rand()%(w - 2*r));
    point.setY(r + rand()%(h - 2*r));
    color = QColor::fromRgb(rand()%256, rand()%256, rand()%256);
    vx = 5 + rand()%10;
    vy = 5 + rand()%10;
    if(rand()%2 == 0) vx *= -1;
    if(rand()%2 == 0) vy *= -1;
}

void Ball::move(int w, int h)
{
    point += QPoint(vx, vy);
    if(point.x() + r >= w) {
        vx *= -1;
    }
    if(point.y() + r >= h) {
        vy *= -1;
    }
    if(point.x() - r <= 0) {
        vx *= -1;
    }
    if(point.y() - r <= 0) {
        vy *= -1;
    }
}

void Ball::draw(QPainter &painter)
{
    painter.setBrush(QBrush(color, Qt::Dense7Pattern));
    painter.drawEllipse(point.x(), point.y(), r, r);
}

QPoint Ball::getPoint()
{
    return point;
}

int Ball::getx()
{
    return point.x();
}

int Ball::gety()
{
    return point.y();
}
