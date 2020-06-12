#ifndef Triangle_h
#define	Triangle_h

#include "Point.h"

class Triangle : public Point
{
private:
	int a, b, c;
	std::string kind;
	Point first, second, third;
public:
	Triangle();
	Triangle(const Triangle&);
	Triangle(Point&, Point&, Point&);
	Triangle& operator=(const Triangle&);
	~Triangle();

	//methods....

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
};

#endif