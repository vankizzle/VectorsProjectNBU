#ifndef	Vector_h
#define Vector_h

#include <iostream>
#include "Point.h"
#include "Element.h"

class Vector : public Point
{
public:
	Vector();
	Vector(int, int, int);
	Vector(const Point&, const Point&);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	~Vector();

	//task 2
	int vectorLength();
	Vector vectorDirection();
	bool isVectorNull();
	bool vectorParallelism(Vector&);
	bool vectorPerpendicularity(Vector&);

	//task 3

	Vector operator +(const Vector&);
	Vector operator -(const Vector&);
	int operator *(const Vector&);
	//...

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
};

#endif