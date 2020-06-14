#include "Vector.h"

Vector::Vector() : Point() {}

Vector::Vector(int i, int j, int k)
{
	setX(i);
	setY(j);
	setZ(k);
} //first realization

Vector::Vector(const Point& A, const Point& B) : Vector(B.getX() - A.getX(), B.getY() - A.getY(), B.getZ() - A.getZ())
{
	A_ = A;
	B_ = B;
} //second realization

Vector::Vector(const Vector& rhs) : Point() {} //copy ctor of the Point 

Vector& Vector::operator=(const Vector& rhs) {
	if (this != &rhs) {
		Point::operator=(rhs); //assignment operator of the Point
	}
	return *this;
}

Vector::~Vector() {
	std::cout << "Destructor for Vector called here.\n";
}

//task 2
int Vector::vectorLength(int x, int y, int z) {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::vectorDirection() {
	int x = getX();
	int y = getY();
	int z = getZ();

	double i, j, k;
	i = x / vectorLength(x, y, z);
	j = y / vectorLength(x, y, z);
	k = z / vectorLength(x, y, z);
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

int Vector::operator *(const Vector& rhs) {
	std::cout << "The result after multiplication is a real number with value ";
	return getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ();
}

//...

std::ostream& Vector::ins(std::ostream& out)const {	
	return out << "\nVector has  cordinates: \nx= " << getX() << "\ny= " << getY() << "\nz= " << getZ() << std::endl;
}

std::istream& Vector::ext(std::istream& in) {
	return in;
}

Point Vector::GetA()
{
	return A_;
}

Point Vector::GetB()
{
	return B_;
}
