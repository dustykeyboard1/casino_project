#include <iostream>
#include "Player.h"
#include "SlotMachine.h"
#include "blackjack.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
    private:
        char command;
        Player player1;
        SlotMachine Slot_player;
        BlackJack Black;
    public:
        //Game();
        void slots();
        void blackjack();
        void enter_casino();
        void print_balance();
        void calaculate_profit();


};

#endif
