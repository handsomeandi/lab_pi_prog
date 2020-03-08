#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>
#include <vector>
#include <algorithm>

void factorization(int n) {
	std::vector<int> factors;
	for (int i = 2; i <= sqrt(n); i++) {
		while (n % i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		factors.push_back(n);
	}
	int times = 1;
	std::vector<int> rep;
	for (std::vector<int>::iterator it = factors.begin(); it != factors.end(); ++it) {
		if (it!=factors.end() - 1 && *it == *(it+1)) {
			times+=1;
		}
		else if (times>1) {
			std::cout << *it << "^" << times;
			times = 1;
		}
		else {
			std::cout << *it;
		}
		if ((it != factors.end() - 1) && (times <= 1)) {
			std::cout << "*";
		}
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	int n;
	std::cin >> n;
	factorization(n);
	return 0;
}