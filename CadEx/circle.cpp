#include"circle.h"

void Circle::print()
{
	cout << "\n\n" << getName() << "\t\tradius:\t" << getRad_X();
}

void Circle::getPointAt(const float t)
{
	cout << "\nat " << t << "\tx:\t" << cos(t) * getRad_X() << "\ty:\t" << sin(t) * getRad_X();
}

void Circle::getDerivativeAt(const float t)
{
	cout << "\nat " << t << "\tderivative:\t" << tan(t - 3.14 / 2);// t e [0; PI / 2]
}