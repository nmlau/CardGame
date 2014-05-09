//
//  Hand.h
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#ifndef __CardGame__Hand__
#define __CardGame__Hand__

#include <iostream>
#include "LinkedList.h"
#include <map>

class Hand: public LinkedList {
public:
    Hand(): LinkedList() {}
    Hand(Hand * a): LinkedList(a) {}
    
//    static Hand * buildHand();
    void add(Card *);
    double evaluateHand();
    double evaluateHandHashMap(map<rank_t, int> & rankMap, map<suit_t, int> & suitMap);
    void rankToMap(map<rank_t, int> & map);
    void suitToMap(map<suit_t, int> & map);
    
private:
};

#endif /* defined(__CardGame__Hand__) */
