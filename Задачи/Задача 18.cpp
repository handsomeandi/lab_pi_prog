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
	int masiv[20];
	int min = 101;
	int max = -101;
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		masiv[i] = -100 + rand() % 201;
	}
	for (int i = 0; i < 20; i++) {
		if (masiv[i] > max) {
			max = masiv[i];
		}
		if (masiv[i] < min) {
			min = masiv[i];
		}
	}
	for (int i = 0; i < 20; i++) {
		std::cout << masiv[i] << " ";
	}
	std::cout << std::endl << min << std::endl;
	std::cout << max;
	return 0;
}