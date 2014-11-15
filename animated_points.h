#ifndef ANIMATED_POINTS_H
#define ANIMATED_POINTS_H

#include <QWidget>

class Animated_Points : public QWidget
{
    Q_OBJECT
public:
    Animated_Points(QWidget *parent = 0);
    Animated_Points(QWidget *parent, QPointF* points, int size, int per_frame);


    void setAntialiased(bool antialiased);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void set_points(QPointF* points, int size, int per_frame);
signals:

public slots:
    void nextAnimationFrame();

protected:
    void paintEvent(QPaintEvent *event);

private:
int total_points;
int frameNo;
int points_per_frame;
QPointF* point_set;

bool antialiased;

};

#endif // ANIMATED_POINTS_H
