#include <iostream>
#include <iomanip>
#include <vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include "helix.h"

/*
Здравствуйте)
Меня зовут Олег. Я вэб-разработчик, пишу, в основном, на C# + JS (React).
Изучение программирования начинал с C++ ещё в университете, где учился по специальности "Информатика".
Код может содержать "странности" - я пытался как можно скорее выполнить задание.
Например, формулы применимы для интервала [0; PI / 2], хотя могут быть масштабированы, в случае необходимости.
Также класс Круг наследует класс Эллипс, т.к. круг представлен как частный случай эллипса.
Спасибо что уделили мне внимание)
*/

int main()
{
	std::cout << std::setprecision(3);
	const float PI = 3.14f;// rounding
	const int MIN = 5;
	const int MAX = 5;

	std::vector<Curve*> curves;
	std::vector<Circle*> circles;

	int numberOfCurves = rand() % MAX + MIN;
	float radiiSum = 0;

	srand(time(0));
	Curve* toAdd;
	/*
		1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified 
		definitions are below). Each curve should be able to return a 3D point and a first derivative (3D 
		vector) per parameter t along the curve
		2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
		random parameters.
	*/
	cout << "\n\nThe container (Vector) of objects of the curves created in random manner with random parameters:";
	for (int i = 0; i < numberOfCurves; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			toAdd = new Ellipse(rand() % MAX + MIN, rand() % MAX + MIN);
			break;
		case 1:
			toAdd = new Circle(rand() % MAX + MIN);
			break;
		default:
			toAdd = new Helix(rand() % 4 + 2, rand() % MAX + MIN);
			break;
		}
		curves.push_back(toAdd);

		/*
			3. Print coordinates of points and derivatives of all curves in the container at t=PI/4
		*/
		curves[i]->print();
		curves[i]->getPointAt(PI / 4);// t e [0; PI / 2]
		curves[i]->getDerivativeAt(PI / 4);// t e [0; PI / 2]

		/*
			4. Populate a second container that would contain only circles from the first container. Make sure the
			second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
		*/
		if (curves[i]->getName() == "circle")
		{
			circles.push_back((Circle*)curves[i]);
		}
	}

	cout << "\n\n\nThe second container that contains only circles from the first container:";
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i]->print();
	}

	/*
		5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the 
		smallest radius, the last - the greatest.
	*/
	std::sort(circles.begin(), circles.end(), [](const Circle *a, const Circle *b) { return a->getRad_X() < b->getRad_X(); });

	/*
		6. Compute the total sum of radii of all curves in the second container.
	*/
	cout << "\n\n\nSorted:";
	for (int i = 0; i < circles.size(); i++)
	{
		radiiSum += circles[i]->getRad_X();
		circles[i]->print();
	}

	cout << "\n\n\nThe total sum of radii of all curves in the second container:\t" << radiiSum << "\n";


	for (int i = 0; i < curves.size(); i++)
	{
		delete curves[i];
	}
}
