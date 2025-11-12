#include "TicTacToe.h"
#include <iostream>
#include <cassert>

void test_initial_state() {
    TicTacToe game;

    // Test initial current player
    assert(game.getCurrentPlayer() == 'X');

    // Test initial move count
    assert(game.getMoveCount() == 0);

    // Test all cells are empty
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            assert(game.getCell(row, col) == ' ');
        }
    }

    // Test game is not over initially
    assert(!game.isGameOver());

    // Test no winner initially
    assert(game.getWinner() == ' ');

    std::cout << "✓ Initial state test passed\n";
}

void test_valid_move() {
    TicTacToe game;

    // Make a valid move
    bool moveResult = game.makeMove(0, 0);

    // Verify move was successful
    assert(moveResult == true);

    // Verify cell was updated
    assert(game.getCell(0, 0) == 'X');

    // Verify current player switched
    assert(game.getCurrentPlayer() == 'O');

    // Verify move count increased
    assert(game.getMoveCount() == 1);

    std::cout << "✓ Valid move test passed\n";
}

void test_invalid_moves() {
    TicTacToe game;

    // Test out-of-bounds moves
    assert(game.makeMove(-1, 0) == false);
    assert(game.makeMove(3, 0) == false);
    assert(game.makeMove(0, -1) == false);
    assert(game.makeMove(0, 3) == false);

    // Make a valid move first
    game.makeMove(0, 0);

    // Test moving to occupied cell
    assert(game.makeMove(0, 0) == false);

    // Test invalid moves after game is over
    TicTacToe game2;
    game2.makeMove(0, 0); // X
    game2.makeMove(1, 0); // O
    game2.makeMove(0, 1); // X
    game2.makeMove(1, 1); // O
    game2.makeMove(0, 2); // X wins

    // Try to make another move
    assert(game2.makeMove(2, 2) == false);

    std::cout << "✓ Invalid moves test passed\n";
}

void test_winner_detection_row() {
    TicTacToe game;

    // Set up X winning in top row
    game.makeMove(0, 0); // X
    game.makeMove(1, 0); // O
    game.makeMove(0, 1); // X
    game.makeMove(1, 1); // O
    game.makeMove(0, 2); // X wins!

    // Verify winner
    assert(game.getWinner() == 'X');

    // Verify if the game is over
    assert(game.isGameOver());

    std::cout << "✓ Winner detection (row) test passed\n";
}

void test_winner_detection_column() {
    TicTacToe game;

    // Set up O winning in first column
    game.makeMove(0, 1); // X
    game.makeMove(0, 0); // O
    game.makeMove(1, 1); // X
    game.makeMove(1, 0); // O
    game.makeMove(2, 2); // X
    game.makeMove(2, 0); // O wins!

    // Verify winner
    assert(game.getWinner() == 'O');

    std::cout << "✓ Winner detection (column) test passed\n";
}

void test_winner_detection_diagonal() {
    // Test main diagonal
    TicTacToe game1;

    game1.makeMove(0, 0); // X
    game1.makeMove(0, 1); // O
    game1.makeMove(1, 1); // X
    game1.makeMove(1, 2); // O
    game1.makeMove(2, 2); // X wins!

    assert(game1.getWinner() == 'X');

    // Test anti-diagonal
    TicTacToe game2;

    game2.makeMove(0, 2); // X
    game2.makeMove(0, 0); // O
    game2.makeMove(1, 1); // X
    game2.makeMove(0, 1); // O
    game2.makeMove(2, 0); // X wins!

    assert(game2.getWinner() == 'X');

    std::cout << "✓ Winner detection (diagonal) test passed\n";
}

void test_full_board_no_winner() {
    TicTacToe game;

    // Create a tie game
    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(0, 2); // X
    game.makeMove(1, 0); // O
    game.makeMove(1, 1); // O
    game.makeMove(1, 2); // X
    game.makeMove(2, 0); // O
    game.makeMove(2, 1); // X
    game.makeMove(2, 2); // O

    // Verify no winner
    assert(game.getWinner() == ' ');

    // Verify if game is already over
    assert(game.isGameOver());

    std::cout << "✓ Full board no winner test passed\n";
}

int main() {
    std::cout << "Running Tic-Tac-Toe tests...\n\n";

    test_initial_state();
    test_valid_move();
    test_invalid_moves();
    test_winner_detection_row();
    test_winner_detection_column();
    test_winner_detection_diagonal();
    test_full_board_no_winner();

    std::cout << "\nAll tests passed! ✓\n";
    return 0;
}