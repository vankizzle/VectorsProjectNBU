#include "Menu.h"

using namespace std;

const char* FilePath = "D:\\projectVectors.txt";
char userInput[1024];
int cntInput = 0, cntElements = 0;
Element* elementsArr[100];

void ShowMenu()
{
	int selectedOption;

	while (true)
	{
		cout << "Please, select an object: \n"
			<< "1. Point\n"
			<< "2. Vector\n"
			<< "3. Line\n"
			<< "4. Segment\n"
			<< "5. Triangle\n"
			<< "6. Tetrahedron\n"
			<< "7. Exit\n";

		cin >> selectedOption;
		switch (selectedOption)
		{
		case 1:
		{
			WriteToFile(intToChar(selectedOption), true);
			Point p(CreatePointObject());
			ExecutePointOperations(p);
			break;
		}
		case 2:
		{
			WriteToFile(intToChar(selectedOption), true);
			Vector v(CreateVectorObject());
			ExecuteVectorOperations(v);
			break;
		}
		case 3:
		{
			WriteToFile(intToChar(selectedOption), true);

			break;
		}
		case 4:
		{
			WriteToFile(intToChar(selectedOption), true);

			break;
		}
		case 5:
		{
			WriteToFile(intToChar(selectedOption), true);

			break;
		}
		case 6:
		{
			WriteToFile(intToChar(selectedOption), true);

			break;
		}
		case 7:
		{
			if (AskToSave())
			{
				SaveDataToFile(userInput);
			}
			exit(0);
			break;
		}
		default:
			std::cout << "Invalid option..." << '\n';
			break;
		}
		WriteToFile('#', true);
		system("CLS");
	}
}

bool AskToSave()
{
	cout << "Save session to file? y/n" << endl;
	char s;
	cin >> s;
	if (s == 'y')
		return true;
	else
		return false;
}

void SaveDataToFile(char* data)
{
	ofstream stream;

	stream.close();
	stream.open(FilePath);

	if (!stream)
		cout << "Opening file failed" << endl;

	stream << data << endl;

	if (!stream)
		cout << "Write failed" << endl;
}

Point CreatePointObject()
{
	int x, y, z;
	std::cout << "Enter x coordinate: \n";
	cin >> x;
	WriteToFile(intToChar(x), false);
	std::cout << "Enter y coordinate: \n";
	cin >> y;
	WriteToFile(intToChar(y), false);
	std::cout << "Enter z coordinate: \n";
	cin >> z;
	WriteToFile(intToChar(z), false);
	Point temp(x, y, z);
	elementsArr[cntElements++] = new Point(temp);

	WriteToFile(' ', true);
	return temp;
}

Vector CreateVectorObject()
{
	int x, y, z;
	std::cout << "Enter x coordinate: \n";
	cin >> x;
	WriteToFile(intToChar(x), false);
	std::cout << "Enter y coordinate: \n";
	cin >> y;
	WriteToFile(intToChar(y), false);
	std::cout << "Enter z coordinate: \n";
	cin >> z;
	WriteToFile(intToChar(z), false);

	Vector temp(x, y, z);
	elementsArr[cntElements++] = new Vector(temp);

	WriteToFile(' ', true);
	return temp;
}

void ExecutePointOperations(Point& p)
{
	int opt;
	cout << "Avalable Point operations: \n"
		<< "1. Print object\n";
	cin >> opt;

	if (opt == 1)
	{
		WriteToFile(intToChar(opt), true);
		cout << p << '\n';
	}

	system("pause");
}

void ExecuteVectorOperations(Vector& v)
{
	int opt;
	std::cout << "Vector operations: \n"
		<< "1. Get length\n"
		<< "2. Get directional vector\n"
		<< "3. Check if vector is null\n"
		<< "4. Check if vector is parallel /w new vector\n"
		<< "5. Check if vector is perpendicular /w new vector\n"
		<< "6. Make a sum /w new vector \n"
		<< "7. Scalar multiplication /w new vector \n"
		<< "8.Print Vector\n";

	cin >> opt;

	if ( opt > 0 && opt < 9 ) 
	{
		WriteToFile(intToChar(opt), true);
		switch (opt)
		{
			case 1:
			{
				std::cout << v.vectorLength() << '\n';
				break;
			}
		case 2:
		{
			std::cout << v.vectorDirection() << '\n';
			break;
		}
		case 3:
		{
			std::cout << (std::boolalpha) << v.isVectorNull() << '\n';
			break;
		}
		case 4:
		{
			Vector newV(CreateVectorObject());
			std::cout << (std::boolalpha) << v.vectorParallelism(newV) << '\n';
			break;
		}
		case 5:
		{
			Vector newV(CreateVectorObject());
			std::cout << (std::boolalpha) << v.vectorPerpendicularity(newV) << '\n';
			break;
		}
		case 6:
		{
			Vector newV(CreateVectorObject());
			std::cout << (std::boolalpha) << v + newV << '\n';
			break;
		}	
		case 7:
		{
			Vector newV(CreateVectorObject());
			std::cout << v * newV << '\n';
			break;
		}				
		case 8:
		{
			cout << v << '\n';
			break;
		}
		default:
			break;
		}
	}

	system("pause");
}

void WriteToFile(char c, bool endl)
{
	userInput[cntInput++] = c;
	userInput[cntInput++] = ' ';
	if (endl)
	{
		userInput[cntInput++] = '\n';
	}
}

char intToChar(int i) { return (char)('0' + i); }

