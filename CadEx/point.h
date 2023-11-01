#pragma once
#include<iostream>

using std::cout;
using std::endl;

class Point
{
private:
	static short pointsQuant;

	int x, z, y;

public:
	Point() :x(0), z(0), y(0) { cout << endl << ++pointsQuant; }
	Point(const int x, const int z, const int y) :x(x), z(z), y(y) { cout << endl << ++pointsQuant; }
	Point(const Point& var) : x(var.x), z(var.z), y(var.y) { cout << endl << ++pointsQuant; }
	Point(const char x, const char z, const char y) :Point((int)x, (int)z, (int)y) {}

	Point& operator=(const Point&);
	Point operator+(const Point&);
	Point operator-(const Point&);
	Point operator*(const Point&);

	Point& operator=(const int);
	Point operator+(const int);
	Point operator-(const int);
	Point operator*(const int);
	Point operator/(const int);

	friend std::ostream& operator<<(std::ostream&, const Point&);

	//accessors
	inline void setX(const int);
	inline const int getX();

	inline void setZ(const int);
	inline const int getZ();

	inline void setY(const int);
	inline const int getY();

	void coordinate();
	~Point();
};