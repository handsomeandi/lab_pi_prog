#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	setlocale(LC_ALL, "russian");
	int num, guess, rand_num, tryagain;
	bool play = true;
	guess = 5;
	std::cout << "Добро пожаловать в игру Угадай Число" << std::endl;
	guess = 5;
	while (play == true) {
		srand(time(NULL));
		rand_num = rand() % 101;
		std::cout << "Введите число:" << std::endl;
		std::cin >> num;
		if (num == rand_num) {
			std::cout << "Поздравляю! Вы угадали! Хотите сыграть еще раз?(1-ДА)" << std::endl;
			std::cin >> tryagain;
			if (tryagain == 1) {
				play = true;
				guess = 5;
			}
			else {
				play = false;
			}
		}
		else if (num > rand_num) {
			std::cout << "Загаданное число меньше" << std::endl;
			guess -= 1;
		}
		else if (num < rand_num) {
			std::cout << "Загаданное число больше" << std::endl;
			guess -= 1;
		}
		if (guess < 1) {
			std::cout << "Вы проиграли. Было загадано: " << rand_num << " Хотите поробовать еще раз?(1-ДА)" << std::endl;
			std::cin >> tryagain;
			if (tryagain == 1) {
				play = true;
				guess = 5;
			}
			else {
				play = false;
			}
		}
	}
	return 0;
}