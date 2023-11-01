#pragma once
#include"circle.h"

class Helix :public Circle// Helix like a particular case of the Circle
{
private:
	float step;

public:
	Helix() = default;
	Helix(const float _step, const float _rad, const string& _name = "helix") :Circle(_rad, _name)
	{
		step = _step;
	}

	void getPointAt(const float)override;
	void getDerivativeAt(const float)override;

	void print()override;

	void setStep(const float);
	const float getStep()const;

	~Helix() = default;
};