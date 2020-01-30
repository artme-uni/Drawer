#include "circle.h"

void Circle::make_points()
{
    int y;
    int count = 0;

    points.assign(radius * 4 + 4, 0);

    for (int i = center[0] - radius; i <= center[0] + radius; i += 2)
    {
        points[count] = i;
        points[count + 1] = sqrt(pow(radius, 2) - pow(i - center[0], 2)) + center[1];
        count += 2;
    }

    for (int i = center[0] + radius; i >= center[0] - radius; i -= 2)
    {
        points[count] = i;
        points[count + 1] = -sqrt(pow(radius, 2) - pow(i - center[0], 2)) + center[1];
        count += 2;
    }
}


void Circle::set_arg(std::vector<std::string> &args)
{
    radius = std::stoi(args[0]);
    parameters += args[0];
}