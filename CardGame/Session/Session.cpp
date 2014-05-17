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
    deck->shuffle();
    
    int length;
    int & lengthRef = length;
    string * nameArray = UI::getPlayers(lengthRef);
    for (int i = 0; i < lengthRef; i++) {
        players.push_back(Player(nameArray[i],50));
    }
    
//    for (vector<Player>::iterator it = players.begin() ; it != players.end(); it++) {
//        cout << it->getName() << ": ";
//        cout << it->getMoney() << endl;
//    }
    dealCards(5,length); //hard coded to 5 card draw
    evaluateHands();

}

void Session::dealCards(int numOfCards, int numOfPlayers) {
    
    //cycle through players (make a helper function here)
    int index = 0;
    for (vector<Player>::iterator it = players.begin(); index < numOfCards * numOfPlayers; it++, index++) {
        if (it == players.end()) {
            it = players.begin();
        }
        it->getHand()->add(deck->popFront());
    }

}



void Session::evaluateHands() {
    
    int bestHand = 0.00;
    Player * playerWithBestHand = new Player();
    for (vector<Player>::iterator it = players.begin() ; it != players.end(); it++) {
//        it->getHand()->print();
//        cout << it->getHand()->evaluateHand() << endl;
        if (it->getHand()->evaluateHand() > bestHand) {
            bestHand = it->getHand()->evaluateHand();
            playerWithBestHand = &*it;
        }
    }
    cout << playerWithBestHand->getName() << endl;
    playerWithBestHand->getHand()->print();
    cout << playerWithBestHand->getHand()->evaluateHand() << endl;
    
}

