//
//  UI.cpp
//  CardGame
//
//  Created by Nicholas Lau on 4/16/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "UI.h"
#include <string>

//UI is hardcoded for now

int UI::getAmountOfPlayers() {
    return 2;
}

std::string * UI::getNamesofPlayers(int num) {
    //string * stringArray = new string[2] {"Nick", "Daniel"};
    string * stringArray = new string[num] {"Nick", "Daniel"};
    return stringArray;
}