#ifndef DRAWER_ADD_H
#define DRAWER_ADD_H

#include "shape.h"

double totalArea(Shape s);

template<class... Args>
double totalArea(Shape s, Args... args)
{
    return s.square() + totalArea(args...);
}

void printName(std::ostream &output, std::map<std::string, int> &arr, Named s);

template<class... Args>
void printName(std::ostream &output, std::map<std::string, int> &arr, Named s, Args... args)
{
    printName(output, arr, s);
    printName(output, arr, args...);
}

template<class... Args>
void printNames(std::ostream &output, Named s, Args... args)
{
    std::map<std::string, int> arr;

    printName(output, arr, s);
    printName(output, arr, args...);
}

#endif //DRAWER_ADD_H