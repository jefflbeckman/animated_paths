#include "generated_ellipse.h"
#include <QPointF>

Generated_Ellipse::Generated_Ellipse()
{
    this->x_offset = 0;
    this->y_offset = 0;
    this->x_ratio = 1;
    this->y_ratio = 1;
    this->num_points = 100;

    this->generate_points();

}
Generated_Ellipse::Generated_Ellipse(float x_offset, float x_ratio, float y_offset, float y_ratio, int num_points)
{
    this->x_offset = x_offset;
    this->y_offset = y_offset;
    this->x_ratio = x_ratio;
    this->y_ratio = y_ratio;
    this->num_points = num_points;

    this->generate_points();

}
void Generated_Ellipse::generate_points()
{
    float theta = 0;
    this->point_set = new QPointF[num_points];

    //index relates to "time"
    for(int i = 0; i < num_points; ++i)
    {
        this->point_set[i].setX(x_offset + x_ratio*cos(theta));
        this->point_set[i].setY(y_offset + y_ratio*sin(theta));
        theta = theta+2*M_PI/num_points;
    }

}

QPointF* Generated_Ellipse::get_points()
{
    return point_set;
}

Generated_Ellipse::~Generated_Ellipse()
{
    delete [] point_set;
}
