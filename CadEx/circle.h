#pragma once
#include"ellipse.h"

class Circle :public Ellipse// Circle like a particular case of the Ellipse
{
public:
	Circle() = default;
	Circle(const float _rad, const string& _name = "circle") :Ellipse(_rad, _rad, _name) {}

	void getPointAt(const float) const override;
	void getDerivativeAt(const float) const override;

	void print() override;

	~Circle() = default;
};