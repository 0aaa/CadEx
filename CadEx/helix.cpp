#include"helix.h"

void Helix::getPointAt(const float t) const
{
	cout << "\nat " << t << "\tx:\t" << cos(t) * getRadX() << "\ty:\t" << sin(t) * getRadX() << "\tz:\t" << step / (2 * PI) * t;
}

void Helix::getDerivativeAt(const float t) const
{
	cout << "\nat " << t << "\tf':\t" << tan(t - PI / 2);// t e [0; PI / 2]. As projection in the XoY plane 
}

void Helix::print()
{
	cout << "\n\n" << getName() << "\t\tr:\t" << getRadX() << "\tstep:\t" << step;
}

void Helix::setStep(const float _step)
{
	step = _step;
}
const float Helix::getStep() const
{
	return step;
}