#include "Triangle.h"

Triangle& Triangle::operator=(const Triangle& rhs) { //assignment operator
	if (this != &rhs) {
		first = rhs.first;
		second = rhs.second;
		third = rhs.third;
	}
	return *this;
}
Triangle::~Triangle() { 
	std::cout << "Destructor for Triangle class called here.\n";
}

std::ostream& Triangle::ins(std::ostream& out)const {
	Point::ins(out);
	return out << "\nTriangle has the following sides:\nSide a: " << a << "\nSide b: " << b << "\nSide c: " << c << std::endl;
}
std::istream& Triangle::ext(std::istream& in) {
	Point::ext(in);
	return in;
}