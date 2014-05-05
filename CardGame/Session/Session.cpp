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
    
    int length;
    int & lengthRef = length;
    string * nameArray = UI::getPlayers(lengthRef);
//    for (int i = 0; i < (nameArray->size())/2; i++) {
    for (int i = 0; i < lengthRef; i++) {
        players.push_back(Player(nameArray[i]));
    }
    
    
    for (vector<Player>::iterator it = players.begin() ; it != players.end(); ++it) {
        cout << ' ' << it->getName();
    }
    cout << '\n';

}