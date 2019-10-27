#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>


int main() {
	setlocale(LC_ALL, "russian");
	double a, b, x, x1, x2, dx, y, min, max;
	min = std::numeric_limits<double>::infinity();
	max = - std::numeric_limits<double>::infinity();
	std::cout << "Введите a,b,x(нач),x(кон),dx" << std::endl;
	std::cin >> a >> b >> x1 >> x2 >> dx;
	if (dx == 0) {
		std::cout << "Шаг не может быть нулевым.";
	}
	if (x2<x1 && dx > 0 || x2>x1 && dx < 0) {
		std::cout << "Введены неправильные данные.Невозможно прийти из x1 в x2.";
	}
	else {
		for (x = x1; x <= x2+dx; x += dx) {
			if (x <= a) {
				y = exp(x);
			}
			else if (x > a && x < b) {
				y = exp(x) + cos(x);
			}
			else if (x >= b) {
				y = tan(x);
			}
			if (y > max) {
				max = y;
			}
			if (y < min) {
				min = y;
			}
			std::cout << "x = " << x << "; y = " << y << std::endl;
		}
	}
	if (max>-std::numeric_limits<double>::infinity() && min < std::numeric_limits<double>::infinity()) {
		std::cout << "Максимальное значение: " << max << std::endl;
		std::cout << "Минимальное значение: " << min << std::endl;
	}
	return 0;
}