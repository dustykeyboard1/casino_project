#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        size_t _wager;
        int _balance;
        int  _start;
    public:
        //Player();
        void set_wager();
        void set_balance();
        void subtract_balance(size_t amount);
        int return_balance();
        size_t return_wager();
        void print_balance();
        void add_balance(size_t amount);
        int return_start();
        int profit();
};
#endif
