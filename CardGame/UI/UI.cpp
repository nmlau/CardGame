//
//  UI.cpp
//  CardGame
//
//  Created by Nicholas Lau on 4/16/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "UI.h"

//UI is hardcoded for now

int UI::getAmountOfPlayers() {
    return 2;
}

string * UI::getNamesofPlayers(int num) {
    //string * stringArray = new string[2] {"Nick", "Daniel"};
    string * stringArray = new string[num] {"Nick", "Daniel"};
    return stringArray;
}

string * UI::getPlayers(int & length) {
    length = 4;
    string * stringArray = new string[length] {"Nick", "Daniel", "J4", "Ahri"};
    return stringArray;
    
}