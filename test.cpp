#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "parsing.h"

TEST_CASE("Test_1", "Img") {

	std::ifstream in;
	in.open("../examples/image1.txt");
	std::string out = "../examples/image1.bmp";

	parsing(in, out);

	in.close();

	std::ifstream ifs ("../examples/image1.bmp");
	REQUIRE (ifs.is_open() == true);
	ifs.close();
}

TEST_CASE("Test_2", "Rectangle") {

	Rectangle tmp(200, 200);
	tmp.make_points();
	std::vector<int> points = tmp.getSegments();

	REQUIRE(points[0] == -100); 
	REQUIRE(points[1] == -100); 
	REQUIRE(points[2] == 100); 
	REQUIRE(points[3] == -100); 
	REQUIRE(points[4] == 100); 
	REQUIRE(points[5] == 100);
	REQUIRE(points[6] == -100);
	REQUIRE(points[7] == 100);
}

TEST_CASE("Test_3", "Triangle") {

    Triangle tmp(100, 100, -100, 100);
	tmp.make_points();
	std::vector<int> points = tmp.getSegments();

	REQUIRE(points[0] == 0); 
	REQUIRE(points[1] == 0); 
	REQUIRE(points[2] == 100); 
	REQUIRE(points[3] == 100); 
	REQUIRE(points[4] == -100); 
	REQUIRE(points[5] == 100);
}

TEST_CASE("Test_4", "set_center") {

    Triangle tmp(100, 100, -100, 100);
    tmp.set_center(300, 300);
	tmp.make_points();
	std::vector<int> points = tmp.getSegments();

	REQUIRE(points[0] == 300); 
	REQUIRE(points[1] == 300); 
	REQUIRE(points[2] == 400); 
	REQUIRE(points[3] == 400); 
	REQUIRE(points[4] == 200); 
	REQUIRE(points[5] == 400);
}

TEST_CASE("Test_5", "inheritance_Rect") {

    auto tmp = std::make_shared<Rectangle>();

	std::vector<std::string> args = {"200", "200","",""};
	tmp->set_arg(args);

	tmp->make_points();
	std::vector<int> points = tmp->getSegments();

	REQUIRE(points[0] == -100); 
	REQUIRE(points[1] == -100); 
	REQUIRE(points[2] == 100); 
	REQUIRE(points[3] == -100); 
	REQUIRE(points[4] == 100); 
	REQUIRE(points[5] == 100);
	REQUIRE(points[6] == -100);
	REQUIRE(points[7] == 100);
}

TEST_CASE("Test_6", "inheritance_Tri") {

    auto tmp = std::make_shared<Triangle>();

	std::vector<std::string> args = {"100", "100","-100","100"};
	tmp->set_arg(args);

	tmp->make_points();
	std::vector<int> points = tmp->getSegments();

	REQUIRE(points[0] == 0); 
	REQUIRE(points[1] == 0); 
	REQUIRE(points[2] == 100); 
	REQUIRE(points[3] == 100); 
	REQUIRE(points[4] == -100); 
	REQUIRE(points[5] == 100);
}

TEST_CASE("Test_7", "square") {

    Circle tmp(100);
	tmp.make_points();
	
	REQUIRE(tmp.square() == 31200.0);
}

TEST_CASE("Test_8", "Colors") {

    Colored tmp{};
    tmp.set_color("lime");
    std::vector<int> arr = tmp.getColors();

    REQUIRE(arr[0] == 0);
    REQUIRE(arr[1] == 255);
    REQUIRE(arr[2] == 0); 
}

TEST_CASE("Test_9", "Names") {

	std::stringstream out;
	printNames(out, Rectangle(10, 20), Triangle(10,10, 10, 0), Circle(5), Circle(8), Named("Unknown"));

	REQUIRE(out.str() == "Rectangle.1 Triangle.1 Circle.1 Circle.2 Unknown.1 "); 
}

TEST_CASE("Test_10", "Area") {

	std::stringstream out;

	REQUIRE(totalArea(Rectangle(10, 5), Triangle(0, 6, 6, 6)) == 68); 
}
