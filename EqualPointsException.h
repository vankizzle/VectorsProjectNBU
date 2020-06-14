#ifndef EqualPointsException_h
#define EqualPointsException_h

#include<string>
#include<exception>
#include "Point.h"

class EqualPointsException : public std::exception
{
public:
	EqualPointsException(Point& pointA, Point& pointB)
		: firstEqPoint(pointA), secondEqPoint(pointB) 
	{
		
	}

	virtual const std::string GetMessage() {
		std::string output = "First point(";
		output.append(std::to_string(firstEqPoint.getX()))
			.append(", ")
			.append(std::to_string(firstEqPoint.getY()))
			.append(", ")
			.append(std::to_string(firstEqPoint.getZ()))
			.append(") is equal to Second point(")
			.append(std::to_string(secondEqPoint.getX()))
			.append(", ")
			.append(std::to_string(secondEqPoint.getY()))
			.append(", ")
			.append(std::to_string(secondEqPoint.getZ()))
			.append(")!");

		return output;
	}
private:
	Point& firstEqPoint;
	Point& secondEqPoint;
};
#endif