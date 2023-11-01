#pragma once
#include<string>
#include<cstdlib>
#include<ctime>
#include"point.h"

using std::string;

class Curve
{
private:
	const float PI = 3.14f;// rounding
	float rad_X, rad_Y;
	string name;

public:
	Curve() = default;
	Curve(const float _rad_X, const float _rad_Y, const string& _name) :rad_X(_rad_X), rad_Y(_rad_Y), name(_name)
	{
		if (_rad_X <= 0 || _rad_Y <= 0)
		{
			throw std::invalid_argument("Invalid value.");
		}
		rad_X = _rad_X;
		rad_Y = _rad_Y;
	}

	void setRad_X(const float);
	const float getRad_X()const;

	void setRad_Y(const float);
	const float getRad_Y()const;

	void setName(const string);
	const string getName()const;

	virtual void getPointAt(const float) {};
	virtual void getDerivativeAt(const float) {};

	virtual void print() {};

	~Curve() = default;
};