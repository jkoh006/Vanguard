//
//  main.cpp
//  FinalProject
//
//  Created by Owen Dolan on 2/22/22.
//

#include <iostream>
//#include "../header/Menu/Menu.hpp"
#include "../header/Menu/Main_Menu.hpp"
#include "../header/Menu/Fight_Menu.hpp"
#include "../header/Characters/Character.h"
#include "../header/Characters/Archer.h"
#include "../header/Characters/Warrior.h"
#include "../header/Characters/Mage.h"
#include "../header/Characters/Paladin.h"
#include "../header/Characters/Farmer.h"
#include "../header/Items/Healing.h"

using namespace std;

Character* player;

void choosePlayer(int choice) {
    if (choice == 1) {
        player = new Archer();
    }
    else if (choice == 2) {
        player = new Warrior();
    }
    else if (choice == 3) {
        player = new Mage();
    }
    else if (choice == 4) {
        player = new Paladin();
    }
    else if (choice == 5) {
        player = new Farmer();
    }
    else {
        cout << "invalid input received, restart game :) " << endl;
    }

}

int main(int argc, const char * argv[]) {
    Main_Menu begin;
    begin.print();
    int playerChoice = begin.chooseCharacter();
    choosePlayer(playerChoice);
    Item* i = new Healing(1);
    player->addToInventory(i);
    Fight_Menu fight(player);
    fight.print();
    delete player;
    delete i;

    return 0;
}
