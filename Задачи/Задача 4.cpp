#include <iostream>

int main()
{
	setlocale(LC_ALL, "russian");
	double a, b, c;
	std::cout << "Введите 2 значения:" << std::endl;
	std:: cin >> a >> b;
	c = a;
	a = b;
	b = c;
	std::cout << a << " " << b << std::endl;
	std::cout << "Введите 2 значения:" << std::endl;
	std::cin >> a >> b;
	a += b;
	b = a - b;
	a = a - b;
	std::cout << a << " " << b;
	return 0;
}