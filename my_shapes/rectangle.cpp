#include "rectangle.h"

void Rectangle::make_points()
{
    points.assign(8, 0);

    points[0] = center[0] - width / 2;
    points[1] = center[1] - height / 2;

    points[2] = points[0] + width;
    points[3] = points[1];

    points[4] = points[2];
    points[5] = points[3] + height;

    points[6] = points[0];
    points[7] = points[5];
}

void Rectangle::set_arg(std::vector<std::string> &args)
{
    parameters += args[0] + "," + args[1];

    width = std::stoi(args[0]);
    height = std::stoi(args[1]);
}

