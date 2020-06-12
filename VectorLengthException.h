#ifndef VectorLengthException_h
#define VectorLengthException_h

#include<exception>
#include<string>

class VectorLenghtException : public std::exception
{
public:
    virtual const std::string exception1() {
        return "Vector has no direction.";
    }
    virtual const std::string exception2() {
        return "One of the vectors has lenght of 0.";
    }
};

#endif