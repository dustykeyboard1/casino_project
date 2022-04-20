#include "Game.h"

// Game::Game() {
//     char command = ' ';
//     Player player1;
//     SlotMachine Slot_player;
//     BlackJack Black;
// }

void Game::slots() {
    cout << "Are you ready to play?" << endl;
    cout << "Enter 'y' for yes" << endl;
    cin >> command;
    while (command != 'y') {
        cout << "Are you ready to play?" << endl;
        cout << "Enter 'y' for yes" << endl;
        cin >> command;
    }
    while (command == 'y' && player1.return_balance() > 0) {
        player1.set_wager();
        cout << endl;

        player1.add_balance(Slot_player.play_game(player1.return_wager()));
        player1.print_balance();
        cout << "Would you like to play again?" << endl;
        cin >> command;
    }
    cout << "Thank you for playing." << endl;
    cout << "Your final balance is " << player1.return_balance() << endl;
}

void Game::blackjack() {
    Black.play_game();
    char input;
    cout << "Want to play again?" << endl;
    cin >> input;
    while (input == 'y') {
        Black.play_game();
        cin >> input;
    }
}

void Game::enter_casino() {
    player1.set_balance();
    cout << "Would you like to play the slot machine or black jack?" << endl;
    cout << "Enter 'b' for blackjack, or 's' for slots." << endl;
    char input = ' ';
    cin >> input;
    while (input != 'b' && input != 's') {
        cout << "Please enter 'b' or 's'." << endl;
        cin >> input;
    }
    if (input == 's') {
        slots();
    } else if (input == 'b') {
        blackjack();
    }

}

void Game::calaculate_profit() {
    cout << "Your total profit is: " << player1.profit() << endl;
}
