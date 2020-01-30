#include <iostream>
#include "parsing.h"

int main(int argc, char **argv)
{

    if (argc == 3)
    {
        std::string output = argv[2];

            if (strcmp(argv[1], "-") == 0)
            {
                parsing(std::cin, output);
            } else
            {
                std::ifstream input(argv[1]);
                parsing(input, output);
                input.close();
            }
    } else
    {
        std::cerr << "Expected input: file.exe [input.txt] [output.bmp]" << std::endl;
        return -1;
    }


    return 0;
}
