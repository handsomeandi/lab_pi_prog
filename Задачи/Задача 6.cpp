#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "russian");
	double a, b, c, d, x1, x2;
	std::cout << "Введите a,b,c:" << std::endl;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	d = (b * b) - (4 * a * c);
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				std::cout << "x принадлежит R";
			}
			else {
				std::cout << "Введены неверные значения";
			}
		}
		else {
			x1 = -c / b;
			std::cout << "x = " << x1;
		}
	}
	else if (d < 0) {
		std::cout << "Решений нет";
	}
	else if (d == 0) {
		x1 = -b / 2 * a;
		std::cout << "x = " << x1;
	}
	else {
		x1 = (-b + sqrt(d)) / 2 * a;
		x2 = (-b - sqrt(d)) / 2 * a;
		std::cout << "x1 = " << x1 << " x2 = " << x2;
	}

	return 0;
}
