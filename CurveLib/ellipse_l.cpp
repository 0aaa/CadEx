#include "pch.h"
#include"ellipse_l.h"

//static std::string ellipse_name_;
//static float ellipse_rad_x_;
//static float ellipse_rad_y_;
//
//void initEllipse(const float _rad_X, const float _rad_Y, const std::string& _name)
//{
//	ellipse_name_ = _name;
//	try
//	{
//		if (_rad_X <= 0 || _rad_Y <= 0)
//		{
//			throw std::invalid_argument("Invalid value.");
//		}
//		ellipse_rad_x_ = _rad_X;
//		ellipse_rad_y_ = _rad_Y;
//	}
//	catch (const std::invalid_argument& e)
//	{
//		cout << e.what();
//	}
//}
//
//void printEllipse()
//{
//	cout << "\n\n" << ellipse_name_ << "\t\tx-axe:\t" << ellipse_rad_x_ << "\ty-axe:\t" << ellipse_rad_y_;
//}
//
//void getPointAtEllipse(const float t)// 2nd solution : (x, sqrt(1 - x^2 / a^2 * b^2))
//{
//	float gamma = atan2(ellipse_rad_x_ * sin(t), ellipse_rad_y_ * cos(t));
//	cout << "\nat " << t << "\tx:\t" << cos(gamma) * ellipse_rad_x_ << "\ty:\t" << sin(gamma) * ellipse_rad_y_;
//}
//
//void getDerivativeAtEllipse(const float t)
//{
//	float gamma = atan2(ellipse_rad_x_ * sin(t), ellipse_rad_y_ * cos(t));
//	float x = cos(gamma) * ellipse_rad_x_;
//	float y = sin(gamma) * ellipse_rad_y_;
//
//	cout << "\nat " << t << "\tf':\t" << -y / (ellipse_rad_x_ * ellipse_rad_x_ / x - x);// t e [0; PI / 2]
//}


void EllipseL::getPointAt(const float t) const// 2nd solution : (x, sqrt(1 - x^2 / a^2 * b^2))
{
	float gamma = atan2(getRadX() * sin(t), getRadY() * cos(t));
	cout << "\nat " << t << "\tx:\t" << cos(gamma) * getRadX() << "\ty:\t" << sin(gamma) * getRadY();
}

void EllipseL::getDerivativeAt(const float t) const
{
	float gamma = atan2(getRadX() * sin(t), getRadY() * cos(t));
	float x = cos(gamma) * getRadX();
	float y = sin(gamma) * getRadY();

	cout << "\nat " << t << "\tf':\t" << -y / (getRadX() * getRadX() / x - x);// t e [0; PI / 2]
}

void EllipseL::print()
{
	cout << "\n\n" << getName() << "\t\tx-axe:\t" << getRadX() << "\ty-axe:\t" << getRadY();
}