#include "parsing.h"

std::shared_ptr<Shape> make_shape(std::string name)
{
    if (name == "circle" || name == "Circle")
        return std::make_shared<Circle>();
    else if (name == "triangle" || name == "Triangle")
        return std::make_shared<Triangle>();
    else if (name == "rectangle" || name == "Rectangle")
        return std::make_shared<Rectangle>();
    else throw std::runtime_error("bad shape name");
}

void parsing(std::istream &input, std::string output)
{
    char tmp[20];
    input.getline(tmp, 20, 'x');
    int img_width = atoi(tmp);
    input.getline(tmp, 20, '\n');
    int img_height = atoi(tmp);

    bitmap_image img(img_width, img_height);
    img.set_all_channels(255, 255, 255);

    int string_count = 1;
    std::map<std::string, int> arr;

    while (input.good())
    {
        std::string str;
        getline(input, str);
        string_count++;

        std::cmatch result;
        std::regex regular("([\\w]+)"
                           "\\s*" "\\(" "\\s*" "([\\d-]+)" "[\\s]*,?[\\s]*" "([\\d-]*)" "[\\s]*,?[\\s]*" "([\\d-]*)" "[\\s]*,?[\\s]*" "([\\d-]*)" "\\s*" "\\)"
                           "\\s*" "\\[" "\\s*" "([\\d-]+)" "[\\s]*,?[\\s]*" "([\\d-]*)" "\\s*" "\\]"
                           "\\s*" "\\{"  "([\\w\\s,]*)" "\\}" "\\s*");

        if (std::regex_match(str.c_str(), result, regular))
        {
            auto current = make_shape(std::string(result[1]));

            std::vector<std::string> args;

            for (size_t i = 2; i < (result.size() - 3); i++)
            {
                args.push_back(result[i]);
            }

            current->set_arg(args);
            current->set_center(std::stoi(result[result.size() - 3]), std::stoi(result[result.size() - 2]));
            current->make_points();

            current->set_color(std::string(result[8]));

            current->set_identifier(arr);
            std::cout << current->get_identifier() << " : " << current->square() << std::endl;

            drawer(img, current->getSegments(), current->getColors(), img_width);

        } else if (str != "" && str != " ")
        {
            std::cout << "bad input in string number " << string_count << std::endl;
        }
    }

    img.save_image(output);
}

void drawer(bitmap_image &img, const std::vector<int> &points, const std::vector<int> &color, int width)
{
    image_drawer draw(img);
    draw.pen_width(width / 500);
    draw.pen_color(color[0], color[1], color[2]);

    for (int i = 0; i < points.size() - 2; i += 2)
    {
        draw.line_segment(points[i], points[i + 1], points[i + 2], points[i + 3]);
    }

    draw.line_segment(points[0], points[1], points[points.size() - 2], points[points.size() - 1]);
}