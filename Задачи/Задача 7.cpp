#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "russian");
	double a, b, c, ax, ay, bx, by, cx, cy, p, s,method;
	std::cout << "Введите способ нахождения площади - 1(через длинны сторон)/2(через координаты вершин)" << std::endl;
	std::cin >> method;
	if (method == 1) {
		std::cout << "Введите длину стороны a" << std::endl;
		std::cin >> a;
		std::cout << "Введите длину стороны b" << std::endl;
		std::cin >> b;
		std::cout << "Введите длину стороны c" << std::endl;
		std::cin >> c;
		if (c > (a + b) || b > (c + a) || a > (c + b)) {
			std::cout << "Введены неверные значения";
		}
		else {
			p = (a + b + c)/2;
			s = sqrt(p * (p - a) * (p - b) * (p - c));
			std::cout << "S= " << s;
		}
	}
	else if (method == 2) {
		std::cout << "Введите координаты вершины a" << std::endl;
		std::cin >> ax >> ay;
		std::cout << "Введите координаты вершины b" << std::endl;
		std::cin >> bx >> by;
		std::cout << "Введите координаты вершины c" << std::endl;
		std::cin >> cx >> cy;
		if (ax == bx && bx == cx || ay == by && by == cy) {
			std::cout << "Введены неверные значение";
		}
		else {
			s = abs((bx - ax) * (cy - ay) - (cx - ax) * (by - ay))/2;
			std::cout << "S = " << s;
		}
	}
	else{
		std::cout << "Введите 1 или 2";
	}
	return 0;
}
