#ifndef Tetrahedron_h
#define Tetrahedron_h

#include "Point.h"
#include "Triangle.h"

class Tetrahedron : public Point
{
public:
	Tetrahedron(Point&, Point&, Point&, Point&);
	Tetrahedron(const Tetrahedron&);
	Tetrahedron& operator=(const Tetrahedron&);
	~Tetrahedron();

	bool AreAllSidesEqual() const;
	bool IsOrthogonal() const;
	double CalculateSurfaceArea() const;
	double CalculateVolume() const;

	bool operator<(const Point&);
	bool operator>(const Point&);
	bool operator==(const Point&);
private:
	Point a, b, c, d;
	Triangle t1, t2, t3, t4;
};

#endif

