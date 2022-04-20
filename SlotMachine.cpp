#include "SlotMachine.h"
//#include "Game.h"

size_t SlotMachine::play_game(size_t _wager) {
        srand(time(0));
        clear_numbers();
        generate_winning_numbers();
        spin();
        cout << "Your Numbers are: ";
        print_numbers(_playercombo);
        result();
        return calculate_new_balance(_wager);
}

void SlotMachine::generate_winning_numbers() {
    for(size_t index = 0; index < 3; index++) {
        _winningcombo.push_back(rand() % 10 + 1);
    }
}

void SlotMachine::spin() {
    for (size_t index = 0; index < 5; index++) {
        _playercombo.push_back(rand() % 10 + 1);
    }
}

size_t SlotMachine::result() {
    _occurences = 0;
    for (size_t index = 0; index < 5; index++) {
        for (size_t winning_index = 0; winning_index < 3; winning_index++) {
            if(_winningcombo[winning_index] == _playercombo[index]) {
                _occurences++;
                winning_numbers.push_back(_playercombo[index]);
            }
        }
    }
    return _occurences;
}

size_t SlotMachine::calculate_new_balance(size_t _wager) {
    size_t winnings = 0;
    if(_occurences <= 2) {
        cout << "Im sorry, you lost." << endl;
    } else if (_occurences < 2 && _occurences >= 4) {

        cout << "Congradulations! You Won!" << endl;
        winnings = 1.5 * _wager;
        cout << "You won: $" << winnings << endl;
    }
    else {
        cout << "Congradulations! You hit the jackpot!" << endl;
        winnings = _wager * 10;
        cout << "You won: $" << winnings << endl;
    }
    cout << "The winning numbers were:";
    print_numbers(_winningcombo);
    return winnings;

}

void SlotMachine::print_numbers(vector<size_t> vect) {
    for(size_t index = 0; index < vect.size(); index++) {
        cout << vect[index] << ' ';
    }
    cout << endl;
}

void SlotMachine::clear_numbers() {
    _winningcombo.clear();
    _playercombo.clear();
    winning_numbers.clear();
}
