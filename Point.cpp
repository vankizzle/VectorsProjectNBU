#include<iostream>
#include"Element.h"
#include "Point.h"

Point::Point() : x(0), y(0), z(0) {} //def ctor 0 values

Point::Point(int x, int y, int z) : x(x), y(y), z(z) {} //ctor

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

bool Point::operator==(Point& rhs) //comparison f-ion
{
	return (this->x == rhs.x) && (this->y == rhs.y) && (this->z == rhs.z); //get() ??
}

int Point::getX() const { return x; }

int Point::getY() const { return y; }

int Point::getZ() const { return z; }

void Point::setX(int x){ this->x = x; }

void Point::setY(int y){ this->y = y; }

void Point::setZ(int z) { this->z = z; }

std::ostream& Point::ins(std::ostream& out)const {
	return out << "\nPoint has cordinates:\nx= " << x << "\ny= " << y << "\nz= " << z << std::endl;
}

std::istream& Point::ext(std::istream& in) {
	//Element::ext();  no data 
	in >> x >> y >> z;
	return in;
}