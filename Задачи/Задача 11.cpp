#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "russian");
	long long num, fact;
	std::cout << "Введите число:" << std::endl;
	std::cin >> num;
	fact = 1;
	for (long long i = num; i > 0; i--) {
		fact *= i;
	}
	std::cout << fact;
	return 0;
}