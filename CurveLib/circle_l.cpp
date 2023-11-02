#include "pch.h"
#include"circle_l.h"

//static const float PI = 3.14f;
//static std::string circle_name_;
//static float circle_rad_;
//
//void initCircle(const float _rad, const std::string& _name)
//{
//	circle_name_ = _name;
//	try
//	{
//		if (_rad <= 0)
//		{
//			throw std::invalid_argument("Invalid value.");
//		}
//		circle_rad_ = _rad;
//	}
//	catch (const std::invalid_argument& e)
//	{
//		cout << e.what();
//	}
//}
//
//void printCircle()
//{
//	cout << "\n\n" << circle_name_ << "\t\tradius:\t" << circle_rad_;
//}
//
//void getPointAtCircle(const float t)
//{
//	cout << "\nat " << t << "\tx:\t" << cos(t) * circle_rad_ << "\ty:\t" << sin(t) * circle_rad_;
//}
//
//void getDerivativeAtCircle(const float t)
//{
//	cout << "\nat " << t << "\tf':\t" << tan(t - PI / 2);// t e [0; PI / 2]
//}


void CircleL::getPointAt(const float t) const
{
	cout << "\nat " << t << "\tx:\t" << cos(t) * getRadX() << "\ty:\t" << sin(t) * getRadX();
}

void CircleL::getDerivativeAt(const float t) const
{
	cout << "\nat " << t << "\tf':\t" << tan(t - PI / 2);// t e [0; PI / 2]
}

void CircleL::print()
{
	cout << "\n\n" << getName() << "\t\tr:\t" << getRadX();
}