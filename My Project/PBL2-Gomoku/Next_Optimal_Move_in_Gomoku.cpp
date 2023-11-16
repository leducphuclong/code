#include <iostream>

using namespace std;

const int size_board = 15;

struct Move {
    int row, col;
};

char player = 'x', opponent = 'o';

bool isMoveLeft(char board[size_board][size_board]) {
    for (int i = 0; i < size_board; i++) {
        for (int j = 0; j < size_board; j++) {
            if (board[i][j] == '_') {
                return true;
            }
        }
    }
    return false;
}

int evaluate(char board[size_board][size_board]) {
   
}

int main() {
    fd

    return 0;
}