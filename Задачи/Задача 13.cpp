#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "russian");
	long long n, count;
	count = 0;
	std::cout << "Введите число" << std::endl;
	std::cin >> n;
	if (n == 0) {
		count = 0;
	}
	else {
		for (int i = 1; i <= n; i *= 2) {
			count += 1;
		}
	}
	std::cout << count;
	return 0;
}