#ifndef EqualPointsException_h
#define EqualPointsException_h

#include<string>
#include<exception>

class EqualPointsException : public std::exception
{
public:
    virtual const std::string exceptionEqualPoints() {
        return "Cannot construct a figure with equal points."; //which ones coincide ?
    }
};
#endif