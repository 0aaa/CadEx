#include "pch.h"
#include"helix_l.h"

//static const float PI = 3.14f;
//static std::string helix_name_;
//static float helix_rad_;
//static float step_;
//
//void initHelix(const float _step, const float _rad, const std::string& _name)
//{
//	helix_name_ = _name;
//	step_ = _step;
//	try
//	{
//		if (_rad <= 0)
//		{
//			throw std::invalid_argument("Invalid value.");
//		}
//		helix_rad_ = _rad;
//	}
//	catch (const std::invalid_argument& e)
//	{
//		cout << e.what();
//	}
//}
//
//void getPointAtHelix(const float t)
//{
//	cout << "\nat " << t << "\tx:\t" << cos(t) * helix_rad_ << "\ty:\t" << sin(t) * helix_rad_ << "\tz:\t" << step_ / (2 * PI) * t;
//}
//
//void getDerivativeAtHelix(const float t)
//{
//	cout << "\nat " << t << "\tf':\t" << tan(t - PI / 2);// t e [0; PI / 2]. As projection in the XoY plane 
//}
//
//void printHelix()
//{
//	cout << "\n\n" << helix_name_ << "\t\tradius:\t" << helix_rad_ << "\tstep:\t" << step_;
//}


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