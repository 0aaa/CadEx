#include <iomanip>
#include <vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>

#include<omp.h>

#include "helix.h"

#include"helix_l.h"

/*
Здравствуйте)
Меня зовут Олег. Я вэб-разработчик, пишу, в основном, на C# + JS (React).
Изучение программирования начинал с C++ ещё в университете, где учился по специальности "Информатика".
Код может содержать "странности" - я пытался как можно скорее выполнить задание.
Например, формулы применимы для интервала [0; PI / 2], хотя могут быть масштабированы в случае необходимости.
Также класс Круг наследует класс Эллипс, т.к. круг представлен как частный случай эллипса.
Спасибо, что уделили мне внимание)
*/


constexpr int THREAD_NUM = 3;
constexpr float PI = 3.14f;// rounding
constexpr int MIN = 7;
constexpr int MAX = 8;

void byClasses();
void byDll();

int main()
{
	cout << std::setprecision(3);

	byClasses();

	/*
	7. Split implementation into a library of curves (.dll or .so) and executable which uses API of this
	library
	*/

	byDll();
}

void byClasses()
{
	std::vector<Curve*> curves;
	std::vector<Circle*> circles;

	srand(time(0));
	int curves_num = rand() % MAX + MIN;
	float radii_sum = 0;

	Curve* to_add;
	/*
		1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
		definitions are below). Each curve should be able to return a 3D point and a first derivative (3D
		vector) per parameter t along the curve
		2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
		random parameters.
	*/
	cout << "The container (Vector) of objects of the curves created in random manner with random parameters:";
	for (int i = 0; i < curves_num; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			to_add = new Ellipse(rand() % MAX + MIN, rand() % MAX + MIN);
			break;
		case 1:
			to_add = new Circle(rand() % MAX + MIN);
			break;
		default:
			to_add = new Helix(rand() % 4 + 2, rand() % MAX + MIN);
			break;
		}
		curves.push_back(to_add);

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

	/*
		5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
		smallest radius, the last - the greatest.
	*/
	std::sort(circles.begin(), circles.end(), [](const Circle* a, const Circle* b) { return a->getRadX() < b->getRadX(); });

	/*
		6. Compute the total sum of radii of all curves in the second container.
		8. Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel 
		TBB library)
	*/
	cout << "\n\nThe second container that contains only circles from the first container\nSorted:";

	omp_set_num_threads(THREAD_NUM);
	cout << "\nThreads number:\t" << omp_get_max_threads();
	
	int i = 0;
	#pragma omp parallel for schedule (static) shared (circles) private (i) reduction (+: radii_sum)
	{
		for (; i < circles.size(); i++)
		{
			radii_sum += circles[i]->getRadX();
			circles[i]->print();
		}
	}

	cout << "\n\nThe total sum of radii of all curves in the second container:\t" << radii_sum << '\n';


	for (i = 0; i < curves.size(); i++)
	{
		delete curves[i];
	}
}


void byDll()
{
	std::vector<CurveL*> curves;
	std::vector<CircleL*> circles;

	srand(time(0));
	int curves_qty = rand() % MAX + MIN;
	float radii_sum = 0;

	CurveL* to_add;
	/*
		1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
		definitions are below). Each curve should be able to return a 3D point and a first derivative (3D
		vector) per parameter t along the curve
		2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
		random parameters.
	*/
	cout << "\n\nBY DLL\n\nThe container (Vector) of objects of the curves created in random manner with random parameters:";
	for (int i = 0; i < curves_qty; i++)
	{
		switch (rand() % 3)
		{
		case 0:
			to_add = new EllipseL(rand() % MAX + MIN, rand() % MAX + MIN);
			break;
		case 1:
			to_add = new CircleL(rand() % MAX + MIN);
			break;
		default:
			to_add = new HelixL(rand() % 4 + 2, rand() % MAX + MIN);
			break;
		}
		curves.push_back(to_add);

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
			circles.push_back((CircleL*)curves[i]);
		}
	}

	/*
		5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
		smallest radius, the last - the greatest.
	*/
	std::sort(circles.begin(), circles.end(), [](const CircleL* a, const CircleL* b) { return a->getRadX() < b->getRadX(); });

	/*
		6. Compute the total sum of radii of all curves in the second container.
	*/
	cout << "\n\nThe second container that contains only circles from the first container\nSorted:";
	for (int i = 0; i < circles.size(); i++)
	{
		radii_sum += circles[i]->getRadX();
		circles[i]->print();
	}

	cout << "\n\nThe total sum of radii of all curves in the second container:\t" << radii_sum << '\n';


	for (int i = 0; i < curves.size(); i++)
	{
		delete curves[i];
	}
}
