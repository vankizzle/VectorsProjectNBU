#ifndef Triangle_h
#define	Triangle_h

#include "Point.h"

class Triangle : public Point
{
public:
	Triangle(Point&, Point&, Point&);
	Triangle(const Triangle&);
	Triangle& operator=(const Triangle&);
	~Triangle();

	std::string GetTriangleKind();
	double GetTriangleSurface();
	double GetTrianglePerimeter();
	Point& GetTriangleInCentre();

	//Operators Overloading
	Point& operator<(const Triangle&);
	Point& operator>(const Triangle&);
	Point& operator==(const Triangle&);

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
private:
	int a, b, c;
	Point first, second, third;
};

#endif