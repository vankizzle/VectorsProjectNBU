#include "Line.h"

Line::Line()
{
	pointA_ = Point(0, 0, 0);
	pointB_ = Point(0, 0, 0);
	vectAB_ = Vector(0, 0, 0);
	setX(pointA_.getX() +  (pointB_.getX()));
	setY(pointA_.getY() +  (pointB_.getY()));
	setZ(pointA_.getZ() +  (pointB_.getZ()));
}

Line::Line(const Point& a, const Point& b)
{
	pointA_ = a;
	pointB_ = b;
	vectAB_ = Vector(a, b);
	setX(pointA_.getX() + (pointB_.getX()));
	setY(pointA_.getY() + (pointB_.getY()));
	setZ(pointA_.getZ() + (pointB_.getZ()));
}

Line::Line(const Point& a , const Vector& vect)
{	
	pointA_ = a;	
	vectAB_ = vect;
	pointB_ = vectAB_.GetB();
	setX(pointA_.getX() + (pointB_.getX()));
	setY(pointA_.getY() + (pointB_.getY()));
	setZ(pointA_.getZ() + (pointB_.getZ()));
}

Line::~Line()
{
}

Vector Line::LineDirection()
{
	return vectAB_.vectorDirection();
}

Vector Line::FindNormalVector() //Returns a perpendicular vector
{
	double l = vectAB_.getX();
	double m = vectAB_.getY();
	double n = vectAB_.getZ();

	double x1 = pointA_.getX();
	double y1 = pointA_.getY();
	double z1 = pointA_.getZ();

	double k = -(l * x1 + m * y1 + n * z1) / (pow(l, 2) + pow(m, 2) + pow(n, 2));

	double vectX = (l * k) + x1;
	double vectY = (m * k) + y1;
	double vectZ = (n * k) + z1;

	return Vector(vectX, vectY, vectZ);
}

int Line::FindAngleInRadians(Line n) //angle between the two lines
{
	double x1 = vectAB_.getX(); 
	double y1 = vectAB_.getY();
	double z1 = vectAB_.getZ();

	double x2 = n.GetLineVector().getX();
	double y2 = n.GetLineVector().getY();
	double z2 = n.GetLineVector().getZ();

	double cos_of_angle = ((x1 * x2) + (y1 * y2) + (z1 * z2)) / (sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2)));

	return(acos(cos_of_angle) * 180.0 / 3.14);
}

bool Line::operator+(const Point& p)
{
	double x = p.getX();
	double y = p.getY();
	double z = p.getZ();

	double x1 = pointA_.getX(); 
	double y1 = pointA_.getY();
	double z1 = pointA_.getZ();
	
	double x2 = pointB_.getX(); 
	double y2 = pointB_.getY();
	double z2 = pointB_.getZ();

	double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
	double AP = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));
	double PB = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) + (z2 - z) * (z2 - z));

	if (AB == AP + PB)	
		return true;
	
	return false;
}



std::ostream& Line::ins(std::ostream& out) const
{
	return out << "\Line has  cordinates: \nx= " << this->vectAB_.getX() << "\ny= " << this->vectAB_.getY() << "\nz= " << this->vectAB_.getZ() << std::endl;
}

std::istream& Line::ext(std::istream& in)
{
	return in;
}

Point Line::GetLinePointA()
{
	return pointA_;
}

Point Line::GetLinePointB()
{
	return pointB_;
}

Vector Line::GetLineVector()
{
	return vectAB_;
}

bool Line::operator||(const Line& line)
{

	double x1 = vectAB_.getX();
	double y1 = vectAB_.getY();
	double z1 = vectAB_.getZ();
	
	double x2 = line.vectAB_.getX();
	double y2 = line.vectAB_.getY();
	double z2 = line.vectAB_.getZ();

	if ((x1 / x2) == (y1 / y2) == (z1 / z2))	
		return true;
	
	return false;
}

bool Line::operator==(const Line& line)
{
	double Vec_x1 = vectAB_.getX();
	double Vec_y1 = vectAB_.getY();
	double  Vec_z1 = vectAB_.getZ();
	
	double  Vec_x2 = line.vectAB_.getX();
	double Vec_y2 = line.vectAB_.getY();
	double Vec_z2 = line.vectAB_.getZ();

	double x1 =this->getX(); 
	double y1 = this->getY();
	double z1 = this->getZ();
	double x2 = line.getX();
	double y2 = line.getY();
	double z2 = line.getZ();

	if ((Vec_x1 / Vec_x2) == (Vec_y1 / Vec_y2) == (Vec_z1 / Vec_z2) && ((x1 == x2) || (y1 == y2) || (z1 == z2)))
		return true;
	
    return false;
	
}

bool Line::operator&&(const Line& line)
{
	double x1 = getX();
	double y1 = getY(); 
	double z1 = getZ();

	double x2 = line.getX();
	double y2 = line.getY();
	double z2 = line.getZ();

	if ((x1 == x2) || (y1 == y2) || (z1 == z2))
		return true;
	
	return false;	
}

bool Line::operator!=(const Line& line)
{
	double x1 = pointA_.getX(); 
	double y1 = pointA_.getY();
	double z1 = pointA_.getZ();

	double x2 = line.pointB_.getX();
	double y2 = line.pointB_.getY();
	double z2 = line.pointB_.getZ();

	double Vec_x1 = vectAB_.getX();
	double Vec_y1 = vectAB_.getY();
	double Vec_z1 = vectAB_.getZ();

	double  Vec_x2 = line.vectAB_.getX();
	double  Vec_y2 = line.vectAB_.getY();
	double  Vec_z2 = line.vectAB_.getZ();

	double d = (x2 - x1) * ((Vec_y1 * Vec_z2)
		- (Vec_z1 * Vec_y2)) - (y2 - y1) * ((Vec_x1 * Vec_z2)
			- (Vec_z1 * Vec_x2)) + (z2 - z1) * ((Vec_x1 * Vec_y2)
				- (Vec_z1 * Vec_x2));

	if (d != 0)	
		return true;

	return false;
}

bool Line::operator|(const Line& line)
{
	double x1 = vectAB_.getX();
	double y1 = vectAB_.getY();
	double z1 = vectAB_.getZ();

	double x2 = line.vectAB_.getX();
	double y2 = line.vectAB_.getY();
	double z2 = line.vectAB_.getZ();

	double d = (x1 * x2) + (y1 * y2) + (z1 * z2);

	if (d == 0)
		return true;

	return false;
}
