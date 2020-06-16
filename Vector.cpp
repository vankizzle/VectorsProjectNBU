#include "Vector.h"

Vector::Vector() : Point() {}

Vector::Vector(double i, double j, double k)
{
	setX(i);
	setY(j);
	setZ(k);
} //first realization

Vector::Vector(const Point& A, const Point& B) : Vector(B.getX() - A.getX(), B.getY() - A.getY(), B.getZ() - A.getZ())
{} //second realization

Vector::Vector(const Vector& rhs) : Vector(rhs.getX(), rhs.getY(), rhs.getZ())
{} //copy ctor of the Vector 

Vector& Vector::operator=(const Vector& rhs) {
	if (this != &rhs) {
		Point::operator=(rhs); //assignment operator of the Point
	}
	return *this;
}

Vector::~Vector() {
	//std::cout << "Destructor for Vector called here.\n";
}

//task 2
double Vector::vectorLength() 
{
	return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}

Vector Vector::vectorDirection() {
	double x = getX();
	double y = getY();
	double z = getZ();
	double len = vectorLength();

	double i, j, k;
	i = x / len;
	j = y / len;
	k = z / len;
	return Vector(i, j, k);
}

bool Vector::isVectorNull() {
	return (getX() == 0 && getY() == 0 && getZ() == 0); //return true if is null
}

bool Vector::vectorParallelism(Vector& v) {
	if (this->getX() / v.getX() == this->getY() / v.getY() && this->getY() / v.getY() == this->getZ() / v.getZ()) {
		std::cout << "Vectors are parralel.\n";
		return true;
	}
	else {
		std::cout << "Vectors are not parralel.\n";
		return false;
	}
}

bool Vector::vectorPerpendicularity(Vector& v) {
	if (this->getX() * v.getX() + this->getY() * v.getY() + this->getZ() * v.getZ() == 0) {
		std::cout << "Vectors are perpendicular.\n";
		return true;
	}
	else {
		std::cout << "Vectors are not perpendicular.\n";
		return false;
	}
}

//task 3

Vector Vector::operator +(const Vector& rhs) {
	std::cout << "The result after addition is a new vector with  cordinates:\n";
	return Vector(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}

Vector Vector::operator -(const Vector& rhs) {
	std::cout << "The result after subtraction is a new vector with cordinates:\n";
	return Vector(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}

double Vector::operator *(const Vector& rhs) {
	std::cout << "The result after multiplication is a real number with value ";
	return getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ();
}

double Vector::operator()(const Vector& v2, const Vector& v3) {
	std::cout << "Result after mixed vector multiplication is a real number with value: ";
	return (this->getY() * v2.getZ() - v2.getY() * this->getZ()) * v3.getX()
		- (this->getX() * v2.getZ() - v2.getX() * this->getZ()) * v3.getY()
		+ (this->getX() * v2.getY() - this->getY() * v2.getX()) * v3.getZ();
}

std::ostream& Vector::ins(std::ostream& out)const {	
	return out << "\nVector has  cordinates: \nx= " << getX() << "\ny= " << getY() << "\nz= " << getZ() << std::endl;
}

std::istream& Vector::ext(std::istream& in) {
	return in;
}
