//
//  main.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Session.h"
using namespace std;

//int main(int argc, const char * argv[])
int main()
{
    /* Card tests
    Card * test = new Card(1,1);
    Card * test1 = new Card(2,2);
    Card::join(test, test1);
    cout << test->getRank() << endl;
    cout << test1->getRank() << endl;
    */
    
    /* Deck tests */
    Deck * deck = new Deck();
    deck = Deck::buildDeck();
    deck->shuffle();
    //deck->print();
    
    /* Hand tests */
    Hand * hand = new Hand();
    hand->add(deck->popFront());
    hand->add(deck->popFront());
    hand->add(deck->popFront());
    hand->add(deck->popFront());
    hand->add(deck->popFront());
//    hand->print();
//    double handValue = hand->evaluateHand();
//    cout << handValue << endl;
//    deck->peekFrontAnAmount(5);
    
    Session * session = new Session();
     
}

