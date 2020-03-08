#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits>
#include <vector>
#include <algorithm>


int main() {
	setlocale(LC_ALL, "russian");
	int n, number[10] = {0}, num;
	std::cin >> n;
	for (int i = n; i > 0; i--) {
		std::cin >> num;
		number[num]++;
	}
	for (int i = 0; i < 10; i++) {
		if (number[i]!=0) {
			std::cout << i << ":" << number[i] << std::endl;
		}
	}
	return 0;
}