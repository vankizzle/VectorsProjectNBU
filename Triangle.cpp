#include "Triangle.h"
#include "EqualPointsException.h"

Triangle::Triangle(Point& a, Point& b, Point& c)
{
	if (a == b)
	{
		throw EqualPointsException(a, b);
	}
	else if (a == c)
	{
		throw EqualPointsException(a, c);
	}
	else if (b == c)
	{
		throw EqualPointsException(b, c);
	}

	//TODO: Assign Points
}

std::ostream& Triangle::ins(std::ostream& out)const {
	Point::ins(out);
	return out << "\nTriangle has the following sides:\nSide a: " << a << "\nSide b: " << b << "\nSide c: " << c << std::endl;
}
std::istream& Triangle::ext(std::istream& in) {
	Point::ext(in);
	return in;
}
