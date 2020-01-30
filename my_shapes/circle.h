#ifndef DRAWER_CIRCLE_H
#define DRAWER_CIRCLE_H

#include "../shape/shape.h"

class Circle : public Shape
{
private:
    int radius;

public:

    Circle()
    {
        shape_name = "Circle";
    }

    Circle(int radius) : radius(radius)
    {
        shape_name = "Circle";
        parameters += std::to_string(radius);
        make_points();
    }

    void make_points() override;

    void set_arg(std::vector<std::string> &args) override;
};


#endif //DRAWER_CIRCLE_H
