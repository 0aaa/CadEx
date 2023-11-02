#pragma once
#include"circle_l.h"

#ifdef CURVELIB_EXPORTS
#define CURVELIB_API __declspec(dllexport)
#else
#define CURVELIB_API __declspec(dllimport)
#endif

//extern "C" CURVELIB_API void initHelix(const float _step, const float _rad, const std::string & _name = "helix");
//
//extern "C" CURVELIB_API void getPointAtHelix(const float);
//extern "C" CURVELIB_API void getDerivativeAtHelix(const float);
//
//extern "C" CURVELIB_API void printHelix();


class CURVELIB_API HelixL :public CircleL// Helix like a particular case of the Circle
{
private:
	float step = 0;

public:
	HelixL() = default;
	HelixL(const float _step, const float _rad, const string& _name = "helix") :CircleL(_rad, _name)
	{
		step = _step;
	}

	void getPointAt(const float) const override;
	void getDerivativeAt(const float) const override;

	void print() override;

	void setStep(const float);
	const float getStep() const;

	~HelixL() = default;
};