#include <iostream> 
#include <climits>

using namespace std;

const int size_board = 3, winning_score = 3;

struct Move {
    int row, col;
};

char player = 'x', opponent = 'o', empty_cell = '_';

bool isMoveLeft(char board[size_board][size_board]) {
    for (int i = 0; i < size_board; i++) {
        for (int j = 0; j < size_board; j++) {
            if (board[i][j] == empty_cell) {
                return true;
            }
        }
    }
    return false;
}

char evaluate_board(char board[size_board][size_board]) {
    // Row
    for (int i = 0; i < size_board; i++) {
        int length = (board[i][0] == empty_cell) ? 0 : 1;
        for (int j = 1; j < size_board; j++) {
            // Check if the cell is empty, we continue to the next cell
            if (board[i][j] == empty_cell) 
                continue;
            // If the cell is not empty, 
            // we check if it is the same as the previous cell,
            // they will form a line.
            if (board[i][j] == board[i][j-1]) {
                if (++length == winning_score)
                    return board[i][j];
            } else {
                length = (board[i][j] == empty_cell) ? 0 : 1;
            }
        }
    }
    // Column 
    for (int j = 0; j < size_board; ++j) {
        int length = (board[0][j] == empty_cell) ? 0 : 1;
        for (int i = 1; i < size_board; ++i) {
            // Check if it is a empty cell, we continue to the next cell
            if (board[i][j] == empty_cell)
                continue;
            // If the cell is not empty, 
            // we check if it is the same as the previous cell,
            // they will form a line.
            if (board[i][j] == board[i-1][j]) {
                if (++length == winning_score)
                    return board[i][j];
            } else {
                length = (board[i][j] == empty_cell) ? 0 : 1;
            }
        }
    }
    // Main Diagonal
    int length = (board[0][0] == empty_cell) ? 0 : 1;
    for (int i = 1; i < size_board; ++i)
        if (board[i][i] != empty_cell && board[i][i] == board[i-1][i-1]) {
            if (++length == winning_score)
                return board[i][i];
        } else {
            length = (board[i][i] == empty_cell) ? 0 : 1;
        }
    // Secondary Diagonal
    length = 1;
    for (int i = 1; i < size_board; ++i)
        if (board[i][size_board-1-i] != empty_cell && board[i][size_board-1-i] == board[i-1][size_board-1-i+1]) {
            if (++length == winning_score)
                return board[i][size_board-1-i];
        } else {
            length = (board[i][size_board-1-i] == empty_cell) ? 0 : 1;
        }

    return empty_cell;
}

int convert_to_score(char c) {
    if (c == player)
        return INT_MAX;
    else if (c == opponent)
        return INT_MIN;
    else
        return 0;
}

// minimax algorithm (backtracking all situations) 
int minimax(char board[size_board][size_board], int depth, bool isMaximizing) {
    int score = convert_to_score(evaluate_board(board));
    // Leaves Node (Game Over)
    if (score == INT_MAX)
        return score;
    if (score == INT_MIN)
        return score;
    if (!isMoveLeft(board))
        return 0;
    // Take turn
    // We will maximizing player's score and minimizing oppenent's score
    // That mean, assume we play the best move for ourself and my oppenent play the
    // worst move for ourself
    int best_score = (isMaximizing == true) ? INT_MIN : INT_MAX;
    for (int i = 0; i < size_board; i++) {
        for (int j = 0; j < size_board; j++) {
            if (board[i][j] == empty_cell) {
                board[i][j] = isMaximizing? player : opponent;
                int score = minimax(board, depth+1, !isMaximizing);
                if (isMaximizing) 
                    best_score = max(best_score, score);
                else
                    best_score = min(best_score, score); 
                board[i][j] = empty_cell;
            }
        }
    }
    return best_score;
}

Move best_move_of_player(char board[size_board][size_board]) {
    int best_score = INT_MIN;
    bool first = true;
    Move best_move;
    for (int i = 0; i < size_board; i++) {
        for (int j = 0; j < size_board; j++) {
            if (board[i][j] == empty_cell) {
                board[i][j] = player;
                int score = minimax(board, 0, false);
                if (score > best_score || (score == best_score && first == true)) {
                    if (score == best_score && first == true)
                        first = false;
                    best_move.row = i;
                    best_move.col = j;
                    best_score = score;
                }
                board[i][j] = empty_cell;
            }
        }
    }
    return best_move;
}



int main(int argc, char* argv[]) {
    char board[size_board][size_board] = {
                {'o','_','_'},
                {'_','_','_'},
                {'_','_','_'}
    };  
    cout << convert_to_score(evaluate_board(board)) << endl;
    Move best_move = best_move_of_player(board);
    cout << "Best Move: " << best_move.row << " " << best_move.col << endl;
    return 0;
}