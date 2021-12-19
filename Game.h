#include <iostream>
#include "Player.h"
#include "SlotMachine.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
    private:
        char command;
        Player player1;
        SlotMachine Slot_player;
        //Blackjack Bjack;
    public:
        void slots();
        void enter_casino();
        void print_balance();
        void calaculate_profit();


};

#endif
