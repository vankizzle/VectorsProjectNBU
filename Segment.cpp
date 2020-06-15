#include "Segment.h"

Segment::Segment(Point& a, Point& b) : a(a), b(b)
{
}

Segment::Segment(const Segment& rhs) : a(rhs.a), b(rhs.b)  // NOLINT(bugprone-copy-constructor-init)
{
	
}

Segment& Segment::operator=(const Segment& rhs)
{
	if (this != &rhs) {
		this->a = rhs.a;
		this->b = rhs.b;
	}

	return *this;
}

Segment::~Segment()
{
	std::cout << "Calling segment destructor here" << std::endl;
}

double Segment::CalculateLength()
{
	return this->a.FindDistanceTo(this->b);
}

Point& Segment::FindMiddlePoint() const
{
	double mx = (this->a.getX() + this->b.getX()) / 2;
	double my = (this->a.getY() + this->b.getY()) / 2;
	double mz = (this->a.getZ() + this->b.getZ()) / 2;

	Point middlePoint = Point(mx, my, mz);

	return middlePoint;
}

bool Segment::operator==(Point& rhs)
{
	const double distanceA = this->a.FindDistanceTo(rhs);
	const double distanceB = rhs.FindDistanceTo(this->b);
	const double segmentLength = this->CalculateLength();

	return distanceA + distanceB == segmentLength;
}


