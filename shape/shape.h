#ifndef DRAWER_SHAPE_H
#define DRAWER_SHAPE_H

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

class Named
{
protected:
    std::string shape_name;
    std::string parameters;
    std::string identifier;

public:
    void set_shapeName(std::string name)
    {
        std::string shapeName(name);
        shape_name = shapeName;
    }

    void set_parameters(std::string cur)
    {
        parameters = cur;
    }

    std::string get_name() const
    {
        return shape_name;
    }

    void set_identifier(std::map<std::string, int> &arr);

    std::string get_identifier()
    {
        return identifier;
    }

    Named()
    {

    }

    Named(std::string str)
    {
        shape_name = str;
    }
};

class Colored
{
protected:
    int red = 0;
    int green = 0;
    int blue = 0;

public:

    Colored()
    {
        
    }

    void set_color(std::string str);

    std::vector<int> getColors() const;
};

class Shape : public Colored, public Named
{
protected:
    std::vector<int> points;
    std::vector<int> center = {0, 0};
public:
    Shape()
    {
    }

    std::vector<int> getSegments() const
    {
        return points;
    }

    void set_center(int x, int y);

    virtual void set_arg(std::vector<std::string> &args)
    {};

    virtual double square() const;

    virtual void make_points()
    {};


};

#endif //DRAWER_SHAPE_H
