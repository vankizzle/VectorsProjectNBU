#include <iostream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include "Menu.h"
using namespace std;

int main()
{
    ShowMenu();
    ////���������� ���������
    //Element* ptr[3]; //����� �� ��������� �� ��� Element, ����� �� ��������� ��� �������� ������� �� ����������
    //ptr[0] = new Point(1, 2, 3);  //debug here and see how ins works
    //ptr[1] = new Vector(Point(1, 2, 3), Point(4, 5, 7));
    //ptr[2] = new Line(Point(1, 2, 3), Point(4, 5, 7));
    //cout << *ptr[0];
   // cout << *ptr[1];
    //cout << *ptr[2];

    //Vector ret = Vector(1, 1, 1);
    //Vector tert = Vector(Point(1, 2, 3), Point(4, 5, 7));

    //Line test = Line(Point(1, 2, 3), Point(4, 5, 7));
    //Line test2 = Line(Point(1, 2, 3), Point(4, 5, 7));
    //bool asd = (test == test2);
    //��� ������ �� ��������� � - � �� ���� ��������, ������������ �� ���� �� ������� �����(��� ����� ���� ��������� �� ����������� � - �� � heap)
    //� �������� �� ������� � ����������� ������� �� ������ ������ ����, ��������� �������� ��� ��������� �� ����������� � - �� �� ���������� ����.
}
