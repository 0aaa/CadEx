#include"curve.h"
#include<iostream>

using std::cout;

void Curve::setRad_X(const float _rad_X)
{
	if (_rad_X <= 0)
	{
		throw std::invalid_argument("Invalid value.");
	}
	rad_X = _rad_X;
}
const float Curve::getRad_X()const
{
	return rad_X;
}

void Curve::setRad_Y(const float _rad_Y)
{
	if (_rad_Y <= 0)
	{
		throw std::invalid_argument("Invalid value.");
	}
	rad_Y = _rad_Y;
}
const float Curve::getRad_Y()const
{
	return rad_Y;
}

void Curve::setName(const string _name)
{
	name = _name;
}
const string Curve::getName()const
{
	return name;
}