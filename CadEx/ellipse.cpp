#include"ellipse.h"

void Ellipse::print()
{
    cout << "\n\n" << getName() << "\t\tx-axe:\t" << getRad_X() << "\ty-axe:\t" << getRad_Y();
}

void Ellipse::getPointAt(const float t)// 2nd solution : (x, sqrt(1 - x^2 / a^2 * b^2))
{
    float gamma = atan2(getRad_X() * sin(t), getRad_Y() * cos(t));
    cout << "\nat " << t << "\tx:\t" << cos(gamma) * getRad_X() << "\ty:\t" << sin(gamma) * getRad_Y();
}

void Ellipse::getDerivativeAt(const float t)
{
    float gamma = atan2(getRad_X() * sin(t), getRad_Y() * cos(t));
    float x = cos(gamma) * getRad_X();
    float y = sin(gamma) * getRad_Y();

    cout << "\nat " << t << "\tderivative:\t" << -y / (getRad_X() * getRad_X() / x - x);// t e [0; PI / 2]
}