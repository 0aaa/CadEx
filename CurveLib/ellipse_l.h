#pragma once
#include"curve_l.h"

#ifdef CURVELIB_EXPORTS
#define CURVELIB_API __declspec(dllexport)
#else
#define CURVELIB_API __declspec(dllimport)
#endif

//extern "C" CURVELIB_API void initEllipse(const float _rad_X, const float _rad_Y, const std::string & _name = "ellipse");
//
//extern "C" CURVELIB_API void printEllipse();
//
//extern "C" CURVELIB_API void getPointAtEllipse(const float);
//extern "C" CURVELIB_API void getDerivativeAtEllipse(const float);


class CURVELIB_API EllipseL :public CurveL
{
public:
	EllipseL() = default;
	EllipseL(const float _rad_x, const float _rad_y, const std::string& _name = "ellipse") :CurveL(_rad_x, _rad_y, _name) {}

	void getPointAt(const float) const override;
	void getDerivativeAt(const float) const override;

	void print() override;

	~EllipseL() = default;
};