//
//  Session.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Session.h"



Session::Session() {
    int num = UI::getAmountOfPlayers();
    //string * nameArray = new string[num];
    //nameArray = UI::getNamesofPlayers(num);
    string * nameArray = UI::getNamesofPlayers(num);
    cout << nameArray[0] <<nameArray[1];
}