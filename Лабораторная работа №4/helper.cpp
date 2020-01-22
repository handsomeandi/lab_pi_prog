#include "helper.h"
#pragma once

Game initGame(char userChar)
{
	Game game;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game.bord[i][j] = ' ';
		}
	}
	int turn = rand()%2;
	game.isUserTurn = turn;
	game.userChar = userChar;
	switch (game.userChar) {
		case('X'):
			game.botChar = 'O';
			break;
		case('O'):
			game.botChar = 'X';
			break;
	}
	return game;
}

void updateDisplay(const Game game)
{
	system("cls");
	std::cout << "   0  " << " 1  " << " 2" << std::endl;
	std::cout << "--------------" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << i << "| ";
		for (int j = 0; j < 3; j++) {
			std::cout << game.bord[i][j] << " | ";
		}
		std::cout << std::endl << "-------------" << std::endl;
	}

}


void botTurn(Game* game)
{
	int counter = 0;
	bool center = true;
		for (int i = 0; i < 3; i++) {
			if (center) {
				for (int j = 0; j < 3; j++) {
					if (game->bord[i][j] == ' ') {
						counter++;
					}
					else {
						center = false;
						break;
					}
				}
			}
			else break;
		}
	
	if (counter == 9) {
		game->bord[1][1] = game->botChar;
	}
	else {
		std::map<int, int> rows = { {0,0}, {1,0}, {2,0} };
		std::map<int, int> cols = { {0,0}, {1,0}, {2,0} };
		std::map<int, int> diag = { {0,0}, {1,0} };
		int count_r = 0;
		int count_c = 0;
		int count_d = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (game->bord[i][j] == game->userChar) {
					rows[i]++;
				}
			}
			if (rows[i] == 2) {
				for (int k = 0; k < 3; k++) {
					if (game->bord[i][k] == ' ') {
						game->bord[i][k] = game->botChar;
						return;
					}
				}
			}
		}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (game->bord[j][i] == game->userChar) {
						cols[i]++;
					}
				}
				if (cols[i] == 2) {
					for (int k = 0; k < 3; k++) {
						if (game->bord[k][i] == ' ') {
							game->bord[k][i] = game->botChar;
							return;
						}
					}
				}
			}
		
			for (int i = 0; i < 3; i++) {
				if (game->bord[i][i] == game->userChar) {
					diag[0]++;
				}
				if (diag[0] == 2) {
					for (int k = 0; k < 3; k++) {
						if (game->bord[k][k] == ' ') {
							game->bord[k][k] = game->botChar;
							return;
						}
					}
				}
			}
			for (int i = 0; i < 3; i++) {
				if (game->bord[i][2-i] == game->userChar) {
					diag[1]++;
				}
				if (diag[1] == 2) {
					for (int k = 0; k < 3; k++) {
						if (game->bord[k][2-k] == ' ') {
							game->bord[k][2-k] = game->botChar;
							return;
						}
					}
				}
			}
		
			int i=0, j=0;
			while (game->bord[i][j] != ' ') {
				i = rand() % 3;
				j = rand() % 3;
			}
			game->bord[i][j] = game->botChar;
			return;
	}
}

void userTurn(Game* game)
{

	std::cout << "¬ведите €чейку(строка, столбец):  ";
	bool correct = false;
	int x, y;
	while (!correct) {
		std::cin >> x >> y;
		if ((x > 2 || x < 0 || y < 0 || y>2) || (game->bord[x][y] != ' ')) {
			std::cout << "¬ведены неверные координаты! ¬ведите обе координаты от 0 до 2(только в пустые €чейки)" << std::endl;
		}
		else {
			correct = true;
			game->bord[x][y] = game->userChar;
		}
	}
}

bool updateGame(Game* game)
{

	for (int i = 0; i < 3; i++) {
		int len1 = 0;
		int len2 = 0;
		for (int j = 0; j < 3; j++) {
			if (game->bord[i][j] == game->userChar) {
				len1++;
			}
			else if (game->bord[i][j] == game->botChar) {
				len2++;
			}
		}
		if ((len1 == 3) || (len2 == 3)) {
			game->status = (len1 == 3 ? USER_WIN : BOT_WIN);
			return true;
		}
	}

	for (int i = 0; i < 3; i++) {
		int len1 = 0;
		int len2 = 0;
		for (int j = 0; j < 3; j++) {
			if (game->bord[j][i] == game->userChar) {
				len1++;
			}
			else if (game->bord[j][i] == game->botChar) {
				len2++;
			}
		}
		if ((len1 == 3) || (len2 == 3)) {
			game->status = (len1 == 3 ? USER_WIN : BOT_WIN);
			return true;
		}
	}

	{
		int len1 = 0;
		int len2 = 0;
		for (int i = 0; i < 3; i++) {
			if (game->bord[i][i] == game->userChar) {
				len1++;
			}
			else if (game->bord[i][i] == game->botChar) {
				len2++;
			}
		}
		if ((len1 == 3) || (len2 == 3)) {
			game->status = (len1 == 3 ? USER_WIN : BOT_WIN);
			return true;
		}
	}

	{
		int len1 = 0;
		int len2 = 0;
		for (int i = 0; i < 3; i++) {
			if (game->bord[i][3 - i] == game->userChar) {
				len1++;
			}
			else if (game->bord[i][3 - i] == game->botChar) {
				len2++;
			}
		}
		if ((len1 == 3) || (len2 == 3)) {
			game->status = (len1 == 3 ? USER_WIN : BOT_WIN);
			return true;
		}
	}
	int filled = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game->bord[i][j] != ' ') {
				filled++;
			}
		}
	}
	if (filled == 9) {
		game->status = NOT_WIN;
		return true;
	}
	game->status = PLAY;
	return false;
}
