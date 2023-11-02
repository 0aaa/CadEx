#include"circle.h"

void Circle::getPointAt(const float t) const
{
	cout << "\nat " << t << "\tx:\t" << cos(t) * getRadX() << "\ty:\t" << sin(t) * getRadX();
}

void Circle::getDerivativeAt(const float t) const
{
	cout << "\nat " << t << "\tf':\t" << tan(t - PI / 2);// t e [0; PI / 2]
}

void Circle::print()
{
	cout << "\n\n" << getName() << "\t\tr:\t" << getRadX();
}