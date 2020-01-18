#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "russian");
	int n,div;
	div = 0;
	std::cout << "Введите число: " << std::endl;
	std::cin >> n;
	for (int i = 2; i < (n - 1); i++) {
		if ((n % i) == 0) {
			div += 1;
		}
	}
	if (div > 0) {
		std::cout << n << " - составное.";
	}
	else {
		std::cout << n << " - простое.";
	}
	return 0;
}