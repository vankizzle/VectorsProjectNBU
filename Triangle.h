#ifndef Triangle_h
#define	Triangle_h

#include "Point.h"

class Triangle : public Point
{
public:
	Triangle();
	Triangle(Point&, Point&, Point&);
	Triangle(const Triangle&);
	Triangle& operator=(const Triangle&);
	~Triangle();

	double getA() const;
	double getB() const;
	double getC() const;

	std::string GetTriangleKind() const;
	double GetTriangleSurface() const;
	double GetTrianglePerimeter() const;
	Point& GetTriangleCentroid() const;

	//Operators Overloading
	bool operator<(const Point&);
	bool operator>(const Point&);
	bool operator==(const Point&);

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
private:
	Point first, second, third;
	double a, b, c;
};

#endif