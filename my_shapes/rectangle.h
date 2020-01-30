#ifndef DRAWER_RECTANGLE_H
#define DRAWER_RECTANGLE_H

#include "../shape/shape.h"

class Rectangle : public Shape
{
private:
    int width;
    int height;
public:

    Rectangle()
    {
        shape_name = "Rectangle";
    };

    Rectangle(int width, int height) : width(width), height(height)
    {
        shape_name = "Rectangle";
        parameters += std::to_string(width) + "," + std::to_string(height);
        make_points();
    }

    void make_points() override;

    void set_arg(std::vector<std::string> &args) override;
};


#endif //DRAWER_RECTANGLE_H
