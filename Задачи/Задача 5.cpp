#include <iostream>

int main()
{
	setlocale(LC_ALL, "russian");
	double x, x0, v0, t, a;
	a = -9.8;
	std::cout << "Введите x0,v0,t" << std::endl;
	std::cin >> x0 >> v0 >> t;
	x = x0 + v0 * t + (a * t * t / 2);
	if (t >= 0) std::cout << "Объект преодолеет расстояние: " << x;
	else std::cout << "Введите t>=0";
	return 0;
}