#include "Player.h"

void Player::set_balance() {
    cout << "How much would you like to enter" << endl;
    cin >> _balance;
    _start = _balance;
}

void Player::subtract_balance(size_t amount) {
    _balance -= amount;
}

int Player::return_balance() {
    return _balance;
}

void Player::add_balance(size_t amount) {
    _balance += amount;
}

int Player::return_start() {
    return _start;
}

int Player::profit() {
    return _balance - _start;
}

void Player::set_wager() {
    cout << "How much would you like to wager?" << endl;
    cin >> _wager;
    while (_wager > return_balance()) {
        print_balance();
        cout << "You do not have enough credits, please enter a smaller wager." << endl;
        cin >> _wager;
    }
    subtract_balance(_wager);
}

void Player::print_balance() {
    cout << "your current balance is: ";
    cout << setprecision(2) << return_balance() << endl;
}

size_t Player::return_wager() {
    return _wager;
}
