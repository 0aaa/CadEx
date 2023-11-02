#pragma once
#include"curve.h"

class Ellipse :public Curve
{
public:
	Ellipse() = default;
	Ellipse(const float _rad_x, const float _rad_y, const string& _name = "ellipse") :Curve(_rad_x, _rad_y, _name) {}

	void getPointAt(const float) const override;
	void getDerivativeAt(const float) const override;

	void print() override;

	~Ellipse() = default;
};