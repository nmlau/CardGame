//
//  Hand.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Hand.h"

void Hand::addToHand(Card * a) {
    this->pushBack(a->getSuit(), a->getRank());
}
