#ifndef Point_h
#define Point_h

#include "Element.h"

class Point : public Element
{
public:
	Point(); 
	Point(int, int, int); 
	Point(const Point& rhs);
	Point& operator=(const Point&);
	~Point();

	bool operator==(Point&);

	int getX() const; 
	int getY() const; 
	int getZ() const; 

	void setX(int); 
	void setY(int); 
	void setZ(int); 

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);

private:
	int x, y, z; //double ?
};

#endif