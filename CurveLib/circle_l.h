#pragma once
#include"ellipse_l.h"

#ifdef CURVELIB_EXPORTS
#define CURVELIB_API __declspec(dllexport)
#else
#define CURVELIB_API __declspec(dllimport)
#endif

//extern "C" CURVELIB_API void initCircle(const float _rad, const std::string & _name = "circle");
//
//extern "C" CURVELIB_API void printCircle();
//
//extern "C" CURVELIB_API void getPointAtCircle(const float);
//extern "C" CURVELIB_API void getDerivativeAtCircle(const float);


class CURVELIB_API CircleL :public EllipseL// Circle like a particular case of the Ellipse
{
public:
	CircleL() = default;
	CircleL(const float _rad, const std::string& _name = "circle") :EllipseL(_rad, _rad, _name) {}

	void getPointAt(const float) const override;
	void getDerivativeAt(const float) const override;

	void print() override;

	~CircleL() = default;
};