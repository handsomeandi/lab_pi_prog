#include <iostream>
#include <string>

int counter = 0;

void checkpath(std::string maze[], int col, int row) {
    maze[col][row] = '#';
    if (maze[col - 1][row] == ' ') {
        int col_temp = col - 1;
        checkpath(maze, col_temp, row);
    }
    else {
        for (int i = 64; i < 92; i++) {
            if (maze[col - 1][row] == (char)i) {
                counter++;
                std::cout << maze[col-1][row] << " ";
                break;
            }
        }
    }
    if (maze[col + 1][row] == ' ') {
        int col_temp = col + 1;
        checkpath(maze, col_temp, row);
    }
    else {
        for (int i = 64; i < 92; i++) {
            if (maze[col + 1][row] == (char)i) {
                counter++;
                std::cout << maze[col + 1][row] << " ";
                break;
            }
        }
    }
    if (maze[col][row - 1] == ' ') {
        int row_temp = row - 1;
        checkpath(maze, col, row_temp);
    }
    else {
        for (int i = 64; i < 92; i++) {
            if (maze[col][row - 1] == (char)i) {
                counter++;
                std::cout << maze[col][row - 1] << " ";
                break;
            }
        }
    }
    if (maze[col][row + 1] == ' ') {
        int row_temp = row + 1;
        checkpath(maze, col, row_temp);
    }
    else {
        for (int i = 64; i < 92; i++) {
            if (maze[col][row + 1] == (char)i) {
                counter++;
                std::cout << maze[col][row+1] << " ";
                break;
            }
        }
    }
}


int main()
{
    std::string maze[25] = {
    "####B######################",
    "# #       #   #      #    #",
    "# # # ###### #### ####### #",
    "# # # #       #   #       #",
    "#   # # ######### # ##### #",
    "# # # #   #       #     # #",
    "### ### ### ############# #",
    "# #   #     # #           #",
    "# # #   ####### ###########",
    "# # # #       # #         C",
    "# # ##### ### # # ####### #",
    "# # #     ### # #       # #",
    "#   ##### ### # ######### #",
    "######### ### #           #",
    "# ####### ### #############",
    "A           #   ###   #   #",
    "# ############# ### # # # #",
    "# ###       # # ### # # # #",
    "# ######### # # ### # # # F",
    "#       ### # #     # # # #",
    "# ######### # ##### # # # #",
    "# #######   #       #   # #",
    "# ####### ######### #######",
    "#         #########       #",
    "#######E############D######"
    };
    int col, row;
    std::cin >> col >> row;
    if (col < 0 || row < 0 || col > 25 || row > 27 || (maze[col][row] == '#')) {
        std::cout << "Wrong coordinates" << std::endl;
    }
    else {
        checkpath(maze, col, row);
        if (counter == 0) {
            std::cout << "No exit" << std::endl;
        }
    }
    return 0;
}
