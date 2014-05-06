//
//  Session.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Session.h"



Session::Session() {
    //int num = UI::getAmountOfPlayers();
    //string * nameArray = new string[num];
    //nameArray = UI::getNamesofPlayers(num);
    deck = Deck::buildDeck();
    
    int length;
    int & lengthRef = length;
    string * nameArray = UI::getPlayers(lengthRef);
    for (int i = 0; i < lengthRef; i++) {
        players.push_back(Player(nameArray[i],50));
    }
    
//    for (vector<Player>::iterator it = players.begin() ; it != players.end(); ++it) {
//        cout << it->getName() << ": ";
//        cout << it->getMoney() << endl;
//    }
    dealCards();

}

bool Session::dealCards() {
    
    //cycle through players (make a helper function here)
    for (vector<Player>::iterator it = players.begin() ; it != players.end(); ++it) {
        it->getHand()->add(deck->popFront());
    }
    cout << deck->size;
    
    //pop cards and add them to players hands
    
    return false;
}
