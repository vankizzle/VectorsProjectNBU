#ifndef Element_h
#define Element_h

#include<iostream>

class Element {
public:
	//������ �� ���������, ������������� ����������� "<<" � ">>" ���� �� ������� ����
	virtual inline std::ostream& ins(std::ostream& out)const = 0; //�������� � ������� ����� - ������ ����� � ������ ������������ � ����
	virtual inline std::istream& ext(std::istream& in) = 0; //����� �� ������ ����� - ������� ������������ �� ������ � ������������ b 
};

inline std::ostream& operator<<(std::ostream& out, const Element& rhs) {
	return rhs.ins(out);
}
inline std::istream& operator>>(std::istream& in, Element& rhs) {
	return rhs.ext(in);
};

#endif

//������ ������ ins � ext �-�� �� ���������� ��� ����� ����, ���� "������� ���������" � ������� �� ����. �� �������� ����������� ins � ext �-��
//� UPCAST � DOWNCAST ���� �� �������� ����� �� ����� ���� �� ������. ��������, � ���� ���� �� � ��������� �� ����� �� � ����� �� ����������