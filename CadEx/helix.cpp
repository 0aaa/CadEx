#include"helix.h"

void Helix::getPointAt(const float t)
{
	const float PI = 3.14f;// rounding
	cout << "\nat " << t << "\tx:\t" << cos(t) * getRad_X() << "\ty:\t" << sin(t) * getRad_X() << "\tz:\t" << step / (2 * PI) * t;
}

void Helix::getDerivativeAt(const float t)
{
	cout << "\nat " << t << "\tderivative:\t" << tan(t - 3.14 / 2);// t e [0; PI / 2]. As projection in the XoY plane 
}

void Helix::print()
{
	cout << "\n\n" << getName() << "\t\tradius:\t" << getRad_X() << "\tstep:\t" << step;
}

void Helix::setStep(const float step_to_set)
{
	step = step_to_set;
}
const float Helix::getStep()const
{
	return step;
}