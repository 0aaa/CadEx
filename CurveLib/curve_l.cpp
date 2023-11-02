#include "pch.h"
#include"curve_l.h"

void CurveL::setRadX(const float _rad_x)
{
	try
	{
		if (_rad_x <= 0)
		{
			throw std::invalid_argument("Invalid value.");
		}
		rad_x = _rad_x;
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what();
	}
}
const float CurveL::getRadX() const
{
	return rad_x;
}

void CurveL::setRadY(const float _rad_y)
{
	try
	{
		if (_rad_y <= 0)
		{
			throw std::invalid_argument("Invalid value.");
		}
		rad_y = _rad_y;
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what();
	}
}
const float CurveL::getRadY() const
{
	return rad_y;
}

void CurveL::setName(const string _name)
{
	name = _name;
}
const string CurveL::getName() const
{
	return name;
}