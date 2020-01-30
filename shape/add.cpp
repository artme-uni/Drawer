#include "add.h"

double totalArea(Shape s)
{
    return s.square();
}

void printName(std::ostream &output, std::map<std::string, int> &arr, Named s)
{
    s.set_identifier(arr);
    output << s.get_identifier() << " ";
}