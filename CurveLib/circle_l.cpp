#include "pch.h"
#include"circle_l.h"

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