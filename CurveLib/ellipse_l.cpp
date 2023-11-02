#include "pch.h"
#include"ellipse_l.h"

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