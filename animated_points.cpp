#include "animated_points.h"

#include <QPainter>

#include <stdlib.h>


Animated_Points::Animated_Points(QWidget *parent) :
    QWidget(parent)
{
    total_points = 0;
    frameNo = 0;
    points_per_frame = 5;
    antialiased = false;
}
Animated_Points::Animated_Points(QWidget *parent, QPointF* points, int size, int per_frame) : QWidget(parent)
{
    antialiased = false;
    this->set_points(points, size, per_frame);
}

void Animated_Points::set_points(QPointF *points, int size, int per_frame)
{
    this->total_points=size;
    this->frameNo=0;
    this->point_set = points;
    this->points_per_frame=per_frame;
}


void Animated_Points::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

QSize Animated_Points::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize Animated_Points::sizeHint() const
{
    return QSize(180, 180);
}


void Animated_Points::nextAnimationFrame()
{
    ++frameNo;
    update();
}

void Animated_Points::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, antialiased);
    painter.translate(width() / 2, height() / 2);

    //If we're going to draw past the end of the list of points,
    //then draw the remaining points and reset the frame counter
    if( (frameNo+1) * points_per_frame > total_points)
    {
        painter.drawPoints(&point_set[(frameNo*points_per_frame)],total_points-(frameNo*points_per_frame));
        frameNo=0;
    }
    else
    {
        painter.drawPoints(&point_set[(frameNo*points_per_frame)],points_per_frame);
    }
}
