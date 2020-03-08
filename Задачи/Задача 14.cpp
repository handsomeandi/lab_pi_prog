#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "russian");
	long long s, l1, r1, l2, r2;
	long long s1, s2;
	long long x1 = 1000000000000000;
	long long x2 = 1000000000000000;
	std::cout << "Введите s,l1,r1,l2,r2" << std::endl;
	std::cin >> s >> l1 >> r1 >> l2 >> r2;
	for (int i = r1; i >= l1; i--) {
		for (int j = r2; j >= r2; j--) {
			if (i + j == s) {
				x1 = i;
				x2 = j;
			}
		}
	}
	if (x1< 10000000000000000000 && x2< 10000000000000000000) {
		std::cout << x1 << " " << x2;
	}
	else {
		std::cout << -1;
	}
	return 0;
}