#pragma once
#include"curve.h"

class Ellipse :public Curve
{
public:
	Ellipse() = default;
	Ellipse(const float _rad_X, const float _rad_Y, const string& _name = "ellipse") :Curve(_rad_X, _rad_Y, _name) {}

	void print()override;

	void getPointAt(const float)override;
	void getDerivativeAt(const float)override;

	~Ellipse() = default;
};