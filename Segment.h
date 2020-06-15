#ifndef	Segment_h
#define Segment_h

#include "Line.h"

class Segment : public Line
{
public:
	Segment(Point& a, Point& b);
	Segment(const Segment&);
	Segment& operator=(const Segment&);
	~Segment();

	double CalculateLength();
	Point& FindMiddlePoint() const;

	bool operator==(Point& rhs);
private:
	Point a, b;
};

#endif