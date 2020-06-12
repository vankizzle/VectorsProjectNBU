#ifndef Element_h
#define Element_h

#include<iostream>

class Element {
public:
	//когато са виртуални, предефинираме операторите "<<" и ">>" само за базовия клас
	virtual inline std::ostream& ins(std::ostream& out)const = 0; //вмъкване в изходен поток - приема поток и вмъква съдържанието в него
	virtual inline std::istream& ext(std::istream& in) = 0; //четем от входен поток - записва информацията от потока в променливата b 
};

inline std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	return rhs.ins(out);
}
inline std::istream& operator>>(std::istream& in, Element& rhs) {
	return rhs.ext(in);
};

#endif

//когато викаме ins и ext ф-ии за референция към базов клас, чрез "късното свързване" и таблици за вирт. се извикват съответните ins и ext ф-ии
//с UPCAST и DOWNCAST може да подаваме обект от базов клас на предеф. операция, а след това да я извикваме за какъв да е обект от йерархията