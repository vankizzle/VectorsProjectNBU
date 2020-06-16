#ifndef	Vector_h
#define Vector_h

#include <iostream>
#include "Point.h"
#include "Element.h"

class Vector : public Point
{
public:
	Vector();
	Vector(double, double, double);
	Vector(const Point&, const Point&);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	~Vector();

	//task 2
	double vectorLength();
	Vector vectorDirection();
	bool isVectorNull();
	bool vectorParallelism(Vector&);
	bool vectorPerpendicularity(Vector&);

	//task 3

	Vector operator +(const Vector&);
	Vector operator -(const Vector&);
	double operator *(const Vector&);
	double operator()(const Vector&, const Vector&);

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
};

#endif