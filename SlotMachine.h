#include <iostream>
#include "Player.h"
#include <cstdlib>
#include<ctime>
#include <vector>

using namespace std;

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

class SlotMachine {
private:
    unsigned int profit;
    size_t _occurences;
    size_t _winning_number;
    vector<size_t> _playercombo;
    vector<size_t> _winningcombo;
    vector<size_t> winning_numbers;
public:
    void print_numbers(vector<size_t> vect);
    size_t play_game(size_t _wager);
    void generate_winning_numbers();
    size_t result();
    void spin();
    void clear_numbers();
    size_t calculate_new_balance(size_t _wager);
    void calaculate_profit();
};

#endif
