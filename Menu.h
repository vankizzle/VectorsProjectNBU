#include <iostream>
#include <fstream>
#include "Point.h"
#include "Segment.h"
#include "Tetrahedron.h"
#include "Line.h"
#include "Triangle.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include "EqualPointsException.h"
#include "Element.h"
void ShowMenu();
bool AskToSave();
void SaveDataToFile(char* data);
Point CreatePointObject();
Vector CreateVectorObject();
Line CreateLineObject();
Triangle CreateTriangleObject();
Segment CreateSegmentObject();
Tetrahedron CreateTetrahedonObject();

void ExecutePointOperations(Point& p);
void ExecuteVectorOperations(Vector& v);
void ExecuteLineOperations(Line& line);
void ExecuteTriangleOperations(Triangle& tri);
void ExecuteSegmentOperations(Segment& seg);
void ExecuteTetrahedronOperations(Tetrahedron& tetr);

void WriteToFile(char c, bool endl);
char intToChar(int i);