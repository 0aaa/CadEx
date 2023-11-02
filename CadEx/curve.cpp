#include"curve.h"

void Curve::setRadX(const float _rad_x)
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
const float Curve::getRadX() const
{
	return rad_x;
}

void Curve::setRadY(const float _rad_y)
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
const float Curve::getRadY() const
{
	return rad_y;
}

void Curve::setName(const string _name)
{
	name = _name;
}
const string Curve::getName() const
{
	return name;
}