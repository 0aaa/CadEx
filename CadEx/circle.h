#pragma once
#include"ellipse.h"

class Circle :public Ellipse// Circle like a particular case of the Ellipse
{
public:
	Circle() = default;
	Circle(const float _rad, const string& _name = "circle") :Ellipse(_rad, _rad, _name) {}

	void print()override;

	void getPointAt(const float)override;
	void getDerivativeAt(const float)override;

	~Circle() = default;
};