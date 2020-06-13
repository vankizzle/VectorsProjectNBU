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

	Point GetA();
	Point GetB();

	//task 2
	int vectorLength(int, int, int);
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
private:
	Point A_;
	Point B_;
};

#endif