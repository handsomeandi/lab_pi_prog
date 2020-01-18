#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "russian");
	double a, b;
	char c;
	std::cout << "Введите выражение:" << std::endl;
	std::cin >> a >> c >> b;
	switch (c)
	{
	case '+':
		std::cout << a + b;
		break;
	case '-':
		std::cout << a - b;
		break;
	case '*':
		std::cout << a * b;
		break;
	case '/':
		if (b == 0) {
			std::cout << "На ноль делить нельзя";
		}
		else {
			std::cout << a / b;
		}
		break;
	default:
		std::cout << "Введено неверное выражение.Введите 2 числа и одну из операций(+, -, * или /) между ними";
		break;
	}
	return 0;
}
