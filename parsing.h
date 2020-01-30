#ifndef LAB_3_PARSING_H
#define LAB_3_PARSING_H

#include "shape/shape.h"
#include "shape/add.h"
#include "my_shapes/rectangle.h"
#include "my_shapes/triangle.h"
#include "my_shapes/circle.h"

#include "bitmap/bitmap_image.hpp"

#include <regex>

void parsing(std::istream &input, std::string output);

void drawer(bitmap_image &img, const std::vector<int> &points, const std::vector<int> &color, int width);

#endif //LAB_3_PARSING_H
