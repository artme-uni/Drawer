#ifndef DRAWER_TRIANGLE_H
#define DRAWER_TRIANGLE_H

#include "../shape/shape.h"

class Triangle : public Shape
{
private:
    int dx1;
    int dy1;
    int dx2;
    int dy2;
public:
    Triangle()
    {
        shape_name = "Triangle";
    }

    Triangle(int dx1, int dy1, int dx2, int dy2) : dx1(dx1), dy1(dy1), dx2(dx2), dy2(dy2)
    {
        shape_name = "Triangle";
        parameters += std::to_string(dx1) + "," + std::to_string(dy1) + "," + std::to_string(dx2) + "," + std::to_string(dy2);
        make_points();
    }

    void make_points() override;

    void set_arg(std::vector<std::string> &args) override;
};

#endif //DRAWER_TRIANGLE_H
