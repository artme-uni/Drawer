#include "shape.h"


void Shape::set_center(int x, int y)
{
    center[0] = x;
    center[1] = y;
}

void Colored::set_color(std::string str)
{
    //str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    if (str == "black")
    {
        red = 0;
        green = 0;
        blue = 0;
    } else if (str == "white")
    {
        red = 255;
        green = 255;
        blue = 255;
    } else if (str == "red")
    {
        red = 255;
        green = 0;
        blue = 0;
    } else if (str == "lime")
    {
        red = 0;
        green = 255;
        blue = 0;
    } else if (str == "blue")
    {
        red = 0;
        green = 0;
        blue = 255;
    } else if (str == "yellow")
    {
        red = 255;
        green = 255;
        blue = 0;
    } else if (str == "cyan")
    {
        red = 0;
        green = 255;
        blue = 255;
    } else if (str == "magenta")
    {
        red = 255;
        green = 0;
        blue = 255;
    } else if (str == "silver")
    {
        red = 192;
        green = 192;
        blue = 192;
    } else if (str == "gray")
    {
        red = 128;
        green = 128;
        blue = 128;
    } else if (str == "maroon")
    {
        red = 128;
        green = 0;
        blue = 0;
    } else if (str == "olive")
    {
        red = 128;
        green = 128;
        blue = 0;
    } else if (str == "green")
    {
        red = 0;
        green = 128;
        blue = 0;
    } else if (str == "purple")
    {
        red = 128;
        green = 0;
        blue = 128;
    } else if (str == "teal")
    {
        red = 0;
        green = 128;
        blue = 128;
    } else if (str == "navy")
    {
        red = 0;
        green = 0;
        blue = 128;
    } else
    {
        str += ",";

        int current = 0;
        for (int i = 0; i < 3; i++)
        {
            std::string buf;

            for (; str[current] != ','; current++)
                buf += str[current];

            current++;

            if (std::stoi(buf) >= 0 && std::stoi(buf) < 256)
            {
                switch (i)
                {
                    case 0 :
                        red = std::stoi(buf);
                        break;
                    case 1 :
                        green = std::stoi(buf);
                        break;
                    case 2 :
                        blue = std::stoi(buf);
                        break;
                }
            }
        }
    }
}

std::vector<int> Colored::getColors() const
{
    std::vector<int> colors;
    colors.push_back(red);
    colors.push_back(green);
    colors.push_back(blue);

    return colors;
}

double Shape::square() const
{
    double square = 0;


    for (int i = 0; i < points.size() - 2; i += 2)
    {
        square += (points[i] * points[i + 3]);
    }

    square += (points[points.size() - 2] * points[1]);

    for (int i = 0; i < points.size() - 2; i += 2)
    {
        square -= (points[i + 2] * points[i + 1]);
    }

    square -= (points[points.size() - 1] * points[0]);

    square = fabs(square / 2);

    return square;
}

void Named::set_identifier(std::map<std::string, int> &arr)
{
    identifier = shape_name + ".";

    if (shape_name != "Rectangle" && shape_name != "Circle" && shape_name != "Triangle")
    {
        identifier += std::to_string(++arr["other"]);
        return;
    }

    std::string id = shape_name + "." + parameters;

    if (arr.find(id) == arr.end())
    {
        arr[shape_name + "_count"] += 1;
        arr[id] = arr[shape_name + "_count"];
    }

    identifier += std::to_string(arr[shape_name + "_count"]);
}