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
    ////полиморфен контейнер
    //Element* ptr[3]; //масив от указатели от тип Element, които ги насочваме към различни класове от йерархията
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
    //При викане на виртуална ф - я се вика версията, принадлежаща на типа на неявния обект(към който сочи указателя на динамичната ф - ия в heap)
    //В обектите от базовия и наследяващи класове се добавя скрито поле, съдържащо указател към таблицата на виртуалните ф - ии за съответния клас.
}
