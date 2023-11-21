#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>

// Size of the game board
const int BOARD_SIZE = 15;

// Class representing the Gomoku game board
class GomokuBoard {
public:
    GomokuBoard() {
        // Initialize the game board and hash table
        board.resize(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
        hashTable.resize(BOARD_SIZE, std::vector<unsigned long long>(BOARD_SIZE, 0));
        currentHash = 0;
        initializeHashTable();
    }

    // Function to make a move on the game board
    void makeMove(int row, int col, int player) {
        currentHash ^= hashTable[row][col]; // XOR the previous hash value
        board[row][col] = player; // Update the game board
        currentHash ^= hashTable[row][col]; // XOR the new hash value
    }

    // Function to print the current game board
    void printBoard() const {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Function to get the current hash value of the game board
    unsigned long long getHash() const {
        return currentHash;
    }

private:
    std::vector<std::vector<int>> board; // Game board
    std::vector<std::vector<unsigned long long>> hashTable; // Hash table for board positions
    unsigned long long currentHash; // Current hash value of the game board

    // Function to initialize the hash table with random values
    void initializeHashTable() {
        std::random_device rd;
        std::mt19937_64 gen(rd());
        std::uniform_int_distribution<unsigned long long> dis;

        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                hashTable[i][j] = dis(gen);
            }
        }
    }
};

int main() {
    GomokuBoard board;

    // Make some moves on the game board
    board.makeMove(7, 7, 1);
    board.makeMove(8, 6, 2);
    board.makeMove(6, 8, 1);

    // Print the current game board
    board.printBoard();

    // Get the current hash value of the game board
    unsigned long long hashValue = board.getHash();
    std::cout << "Hash value: " << hashValue << std::endl;

    return 0;
}