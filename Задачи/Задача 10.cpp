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
	double num, times, res;
	std::cin >> num;
	std::cin >> times;
	res = 1;
	if (times > 0) {
		for (int i = 1; i <= times; i++) {
			res *= num;
		}
	}
	else if (times < 0) {
		times = -times;
		for (int i = 1; i <= times; i++) {
			res *= num;
		}
		res = 1.0 / res;
	}
	std::cout << res;
	return 0;
}