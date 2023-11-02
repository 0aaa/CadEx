#include "pch.h"
#include"helix_l.h"

void HelixL::getPointAt(const float t) const
{
	cout << "\nat " << t << "\tx:\t" << cos(t) * getRadX() << "\ty:\t" << sin(t) * getRadX() << "\tz:\t" << step / (2 * PI) * t;
}

void HelixL::getDerivativeAt(const float t) const
{
	cout << "\nat " << t << "\tf':\t" << tan(t - PI / 2);// t e [0; PI / 2]. As projection in the XoY plane 
}

void HelixL::print()
{
	cout << "\n\n" << getName() << "\t\tr:\t" << getRadX() << "\tstep:\t" << step;
}

void HelixL::setStep(const float _step)
{
	step = _step;
}
const float HelixL::getStep() const
{
	return step;
}