//
//  main.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include <iostream>
#include "Deck.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Card * test = new Card(1,1);
    Card * test1 = new Card(2,2);
    Card::join(test, test1);
    cout << test->getRank() << endl;
    cout << test1->getRank() << endl;
    //Card * test2 = new Card(test, test1, 10);
    LinkedList * test2 = new LinkedList(19,19);
    LinkedList * test3 = new LinkedList(20,20);
    test2->pushBack(21,21);
    test2->pushBack(21,21);
    test2->pushBack(21,21);
    test2->print();
    Deck * deck = new Deck();
    deck = Deck::buildDeck();
    deck->shuffle();
    deck->print();
    
    /* Basic Linked List using Nodes test
    LinkedList * test = new LinkedList(9);
    LinkedList * test2 = new LinkedList(11);
    test2->addNode(10);
    test2->addNode(9);
    test2->addNode(8);
    test2->print();
    test->print();
   // test2 = test2->subtract(test2, test);
    test2 = test2->subtract(test);
    test2->print();
     */
}

