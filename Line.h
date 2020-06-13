#ifndef Line_h
#define Line_h

#include "Vector.h"

class Line : public Vector
{
public:
	Line();
	Line(const Point& a, const Point& b);
	Line(const Point& a, const Vector& b);
	~Line();

	Vector LineDirection();
	Vector FindNormalVector();
	int FindAngleInRadians(Line n);

	Point GetLinePointA();
	Point GetLinePointB();
	Vector GetLineVector();

	bool operator +(const Point&);
	bool operator ||(const Line&);
	bool operator ==(const Line&);
	bool operator &&(const Line&);
	bool operator !=(const Line&);
	bool operator |(const Line&);

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
private:
	Point pointA_;
	Point pointB_;
	Vector vectAB_;
	double time_;
};

#endif