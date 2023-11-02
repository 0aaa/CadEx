#pragma once
#include<string>
#include<cstdlib>
#include<ctime>
#include <iostream>

#ifdef CURVELIB_EXPORTS
#define CURVELIB_API __declspec(dllexport)
#else
#define CURVELIB_API __declspec(dllimport)
#endif

using std::cout;
using std::string;

class CURVELIB_API CurveL
{
private:
	float rad_x, rad_y;
	string name;

protected:
	const float PI = 3.14f;// rounding

public:
	CurveL()
	{
		rad_x = rad_y = 0;
	}
	CurveL(const float _rad_x, const float _rad_y, const string& _name) :rad_x(_rad_x), rad_y(_rad_y), name(_name)
	{
		try
		{
			if (_rad_x <= 0 || _rad_y <= 0)
			{
				throw std::invalid_argument("Invalid value.");
			}
			rad_x = _rad_x;
			rad_y = _rad_y;
		}
		catch (const std::invalid_argument& e)
		{
			cout << e.what();
		}
	}

	void setRadX(const float);
	const float getRadX() const;

	void setRadY(const float);
	const float getRadY() const;

	void setName(const string);
	const string getName() const;

	virtual void getPointAt(const float) const {};
	virtual void getDerivativeAt(const float) const {};

	virtual void print() {};

	~CurveL() = default;
};