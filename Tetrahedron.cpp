#include "Tetrahedron.h"
#include "EqualPointsException.h"

Tetrahedron::Tetrahedron(Point& a, Point& b, Point& c, Point& d)
{
	if (a == b)
	{
		throw EqualPointsException(a, b);
	}
	
	if (a == c)
	{
		throw EqualPointsException(a, c);
	}

	if (a == d)
	{
		throw EqualPointsException(a, d);
	}
	
	if (b == c)
	{
		throw EqualPointsException(b, c);
	}

	if (b == d)
	{
		throw EqualPointsException(b, d);
	}

	if (c == d)
	{
		throw EqualPointsException(c, d);
	}

	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->t1 = Triangle(a, c, d);
	this->t2 = Triangle(a, b, d);
	this->t3 = Triangle(b, c, d);
	this->t4 = Triangle(a, b, c);
}

Tetrahedron::Tetrahedron(const Tetrahedron& rhs) :  // NOLINT(bugprone-copy-constructor-init)
	a(rhs.a), b(rhs.b), c(rhs.c), d(rhs.c), t1(rhs.t1), t2(rhs.t2), t3(rhs.t3), t4(rhs.t4)
{
	
}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& rhs)
{
	if (this != &rhs) {
		this->a = rhs.a;
		this->b = rhs.b;
		this->c = rhs.c;
		this->d = rhs.d;
		this->t1 = rhs.t1;
		this->t2 = rhs.t2;
		this->t3 = rhs.t3;
		this->t4 = rhs.t4;
	}

	return *this;
}

Tetrahedron::~Tetrahedron()
{
	std::cout << "Calling Tetrahedron destructor here..." << std::endl;
}

bool Tetrahedron::AreAllSidesEqual() const
{
	const bool areEqual = this->t1.getA() == this->t1.getB() == this->t1.getC() ==
		this->t2.getA() == this->t2.getC() == this->t3.getC();

	return areEqual;
}

//Don't know how to implement it
bool Tetrahedron::IsOrthogonal() const
{
	return true;
}

double Tetrahedron::CalculateSurfaceArea() const
{
	const double surfaceArea = sqrt(3) * pow(this->t1.getA(), 2);

	return surfaceArea;
}

double Tetrahedron::CalculateVolume() const
{
	const double volume = (1.0 / 12) * sqrt(2) * pow(this->t1.getA(), 2);

	return volume;
}

//Don't know how to implement them
bool Tetrahedron::operator<(const Point&)
{
	return true;
}

bool Tetrahedron::operator>(const Point&)
{
	return true;
}

bool Tetrahedron::operator==(const Point&)
{
	return true;
}
