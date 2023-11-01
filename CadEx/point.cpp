#include"point.h"
#include<fstream>

short Point::pointsQuant = 0;
void Point::coordinate()
{
	using std::ofstream;
	using std::ifstream;
	using std::cout;
	using std::endl;
	using std::cin;

	Point Coord;
	short Xcoord, Zcoord, Ycoord;

	unsigned short input;

	ofstream fileOut;
	ifstream fileIn;

	char buffer;

	do
	{
		//setting values to the private fields via accessors
		cout << endl << endl << "Please, set 3 coordinates:" << endl;

		cin >> Xcoord;
		Coord.setX(Xcoord);

		cin >> Zcoord;
		Coord.setZ(Zcoord);

		cin >> Ycoord;
		Coord.setY(Ycoord);

		//ADDITIONAL. reading of the private fields to the file via accessors
		fileOut.open("file.txt");

		fileOut << endl << endl << "Please, check 3 coordinates:\t";

		fileOut << Coord.getX() << '\t' << Coord.getY() << '\t' << Coord.getZ();

		//ADDITIONAL. request for set a new coordinates
		fileOut << endl << endl << "Do you want set new coordinates?" << endl
			<< "1 / 0" << endl;

		fileOut.close();

		fileIn.open("file.txt");

		do
		{
			buffer = fileIn.get();
			cout << buffer;
		} while (!fileIn.eof());

		fileIn.close();

		cin >> input;

	} while (input);
}

Point& Point::operator=(const Point& var)
{
	this->x = var.x;
	this->y = var.y;
	this->z = var.z;
	return *this;
}
Point Point::operator+(const Point& var)
{
	return Point(this->x + var.x, this->y + var.y, this->z + var.z);
}
Point Point::operator-(const Point& var)
{
	return Point{ this->x - var.x, this->y - var.y, this->z - var.z };
}
Point Point::operator*(const Point& var)
{
	return Point{ this->x * var.x, this->y * var.y, this->z * var.z };
}

Point& Point::operator=(const int var)
{
	this->x = var;
	this->y = var;
	this->z = var;
	return *this;
}
Point Point::operator+(const int var)
{
	return Point{ this->x + var, this->y + var, this->z + var };
}
Point Point::operator-(const int var)
{
	return Point{ this->x - var,this->y - var, this->z - var };
}
Point Point::operator*(const int var)
{
	return Point{ this->x * var, this->y * var, this->z * var };
}
Point Point::operator/(const int var)
{
	return Point{ this->x / var, this->y / var, this->z / var };
}

std::ostream& operator<<(std::ostream& output, const Point& var)
{
	return output << "x:\t" << var.x << "\ty:\t" << var.y << "\tz:\t" << var.z;
}

void Point::setX(const int Xcoord)
{
	x = Xcoord;
}
const int Point::getX()
{
	return x;
}

void Point::setY(const int Ycoord)
{
	y = Ycoord;
}
const int Point::getY()
{
	return y;
}

void Point::setZ(const int Zcoord)
{
	z = Zcoord;
}
const int Point::getZ()
{
	return z;
}

Point::~Point()
{
	using std::cout;
	using std::endl;

	pointsQuant--;

	cout << endl << endl << "*distructor Point:\t\t" << pointsQuant << "\tleft";
}