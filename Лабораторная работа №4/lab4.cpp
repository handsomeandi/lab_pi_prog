#include <iostream>
#include "helper.h"

int main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	char user = ' ';
	do {
		std::cout << "Введите ваш символ(X/O):" << std::endl;
		std::cin >> user;
	} while ((user != 'O') && user != 'X');

	Game game = initGame(user);
	if (game.isUserTurn) {
		while (true) {
			userTurn(&game);
			updateDisplay(game);
			if (updateGame(&game)) {
				break;
			}
			else {
				botTurn(&game);
				updateDisplay(game);
				if (updateGame(&game)) break;
			}
		}
	}
	else {
		while (true) {
			botTurn(&game);
			updateDisplay(game);
			if (updateGame(&game)) {
				break;
			}
			else {
				userTurn(&game);
				updateDisplay(game);
				if (updateGame(&game)) break;
			}
		}
	}
	if (game.status == USER_WIN) {
		std::cout << "Вы победили" << std::endl;
	}
	else if (game.status == BOT_WIN) {
		std::cout << "Вы проиграли" << std::endl;
	}
	else if (game.status == NOT_WIN) {
		std::cout << "Ничья" << std::endl;
	}
	return 0;
}
