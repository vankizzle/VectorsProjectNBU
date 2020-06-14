#ifndef Point_h
#define Point_h

#include "Element.h"

class Point : public Element
{
public:
	Point(); 
	Point(double, double, double); 
	Point(const Point& rhs);
	Point& operator=(const Point&);
	~Point();

	bool operator==(Point&);

	double getX() const; 
	double getY() const; 
	double getZ() const; 

	void setX(double); 
	void setY(double); 
	void setZ(double);

	//Helper functions
	double FindDistanceTo(Point&) const;

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);

private:
	double x, y, z;
};

#endif