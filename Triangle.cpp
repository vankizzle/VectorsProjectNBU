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

	this->first = a;
	this->second = b;
	this->third = c;

	this->a = this->second.FindDistanceTo(this->third);
	this->b = this->first.FindDistanceTo(this->third);
	this->c = this->first.FindDistanceTo(this->second);
}

Triangle::Triangle(const Triangle& rhs)  // NOLINT(bugprone-copy-constructor-init)
	: first(rhs.first), second(rhs.second), third(rhs.third), a(rhs.a), b(rhs.b), c(rhs.c)
{
	
}

Triangle& Triangle::operator=(const Triangle& rhs)
{
	if (this != &rhs) {
		first = rhs.first;
		second = rhs.second;
		third = rhs.third;
		a = rhs.a;
		b = rhs.b;
		c = rhs.c;
	}
	
	return *this;
}

Triangle::~Triangle()
{
	std::cout << "Triangle destructor is here" << std::endl;
}

std::string Triangle::GetTriangleKind() const
{
	std::string typeBySideLength;
	std::string typeByAngle;

	if (this->a == this->b == this->c)
	{
		typeBySideLength = "Equilateral";
	}
	else if (this->a == this->b || this->a == this->c || this->b == this->c)
	{
		typeBySideLength = "Isosceles";
	}
	else
	{
		typeBySideLength = "Scalene";
	}

	const double sidesSquare = pow(this->a, 2) + pow(this->b, 2);

	if (sidesSquare > pow(this->c, 2))
	{
		typeByAngle = "Acute";
	}
	else if (sidesSquare < pow(this->c, 2))
	{
		typeByAngle = "Obtuse";
	}
	else
	{
		typeByAngle = "Right";
	}

	return typeBySideLength + "/" + typeByAngle;
}

double Triangle::GetTriangleSurface() const
{
	double p = (this->a + this->b + this->c) / 2.0;

	return sqrt((p * (p - this->a) * (p - this->b) * (p - this->c)));
}

double Triangle::GetTrianglePerimeter() const
{
	return this->a + this->b + this->c;
}

Point& Triangle::GetTriangleCentroid() const
{
	double cx = (this->first.getX() + this->second.getX() + this->third.getX()) / 3.0;
	double cy = (this->first.getY() + this->second.getY() + this->third.getY()) / 3.0;
	double cz = (this->first.getZ() + this->second.getZ() + this->third.getZ()) / 3.0;

	Point centroid = Point(cx, cy, cz);

	return centroid;
}

bool Triangle::operator<(const Point& rhs)
{
	
}

bool Triangle::operator>(const Point&)
{
	
}

bool Triangle::operator==(const Point&)
{
	
}


std::ostream& Triangle::ins(std::ostream& out)const {
	Point::ins(out);
	return out << "\nTriangle has the following sides:\nSide a: " << a << "\nSide b: " << b << "\nSide c: " << c << std::endl;
}
std::istream& Triangle::ext(std::istream& in) {
	Point::ext(in);
	return in;
}
