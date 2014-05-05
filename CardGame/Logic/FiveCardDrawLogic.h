//
//  FiveCardDrawLogic.h
//  CardGame
//
//  Created by Nicholas Lau on 3/18/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#ifndef __CardGame__FiveCardDrawLogic__
#define __CardGame__FiveCardDrawLogic__

#include <iostream>
#include "session.h"

/*
 datamembers:
 -handsize
 -dealer
 functions:
 -tell session what phase to do next
 -evaluate hand from session
 
 Gameplay:
 Ante
 Deal
 Bet (left of dealer)
 Replace cards (1-4 from left of dealer) -> discard, burn, deal
 Bet again
 Check hands to find winner
 
 Hands:
 Straight Flush
 Four of a Kind
 Full House
 Flush
 Straight
 3 of a kind
 2 pair
 1 pair
 high card
 
 */



class FiveCardDrawLogic {
public:
private:
};


#endif /* defined(__CardGame__FiveCardDrawLogic__) */
