#include<iostream>
#include"Element.h"
#include "Point.h"

Point::Point() : x(0), y(0), z(0) {} //def ctor 0 values

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {} //ctor

Point::Point(const Point& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {} //copy ctor

Point& Point::operator=(const Point& rhs) { //assignment operator
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
	}
	return *this;
}

Point::~Point() {
	std::cout << "Destructor for Point class called here.\n";
}

bool Point::operator==(Point& rhs) //comparison t1-ion
{
	return (this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z); //get() ??
}

double Point::getX() const { return x; }

double Point::getY() const { return y; }

double Point::getZ() const { return z; }

void Point::setX(double x){ this->x = x; }

void Point::setY(double y){ this->y = y; }

void Point::setZ(double z) { this->z = z; }

double Point::FindDistanceTo(Point& other) const
{
	return sqrt((pow((this->getX() - other.getX()), 2))
		+ (pow((this->getY() - other.getY()), 2))
		+ (pow((this->getZ() - other.getZ()), 2)));
}

std::ostream& Point::ins(std::ostream& out)const {
	return out << "\nPoint has cordinates:\nx= " << x << "\ny= " << y << "\nz= " << z << std::endl;
}

std::istream& Point::ext(std::istream& in) {
	//Element::ext();  no data 
	in >> x >> y >> z;
	return in;
}