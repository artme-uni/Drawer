#include "triangle.h"

void Triangle::make_points()
{
    points.assign(6, 0);

    points[0] = center[0];
    points[1] = center[1];
    points[2] = center[0] + dx1;
    points[3] = center[1] + dy1;
    points[4] = center[0] + dx2;
    points[5] = center[1] + dy2;
}

void Triangle::set_arg(std::vector<std::string> &args)
{
    dx1 = std::stoi(args[0]);
    dy1 = std::stoi(args[1]);
    dx2 = std::stoi(args[2]);
    dy2 = std::stoi(args[3]);

    parameters += args[0] + "," + args[1] + "," + args[2] + "," + args[3];
}

