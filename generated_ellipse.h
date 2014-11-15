#ifndef GENERATED_ELLIPSE_H
#define GENERATED_ELLIPSE_H

#include <QPointF>
#include <math.h>

class Generated_Ellipse
{
public:
    //constructors generate the set of points when initialized
    Generated_Ellipse();
    Generated_Ellipse(float x_offset, float x_ratio, float y_offset, float y_ratio, int num_points);

    //destructors
    ~Generated_Ellipse();

    //accesses set of points for this ellipse
    QPointF* get_points();

private:
    void generate_points();
    int num_points;
    QPointF *point_set;
    float x_offset, x_ratio, y_offset, y_ratio;
};

#endif // GENERATED_ELLIPSE_H
