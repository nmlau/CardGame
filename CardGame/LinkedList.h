//
//  LinkedList.h
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

#include <iostream>
#include "Card.h"
using namespace std;
typedef Card * storage_t;

class LinkedList {
private:
    static int s_count;

public:
    storage_t head;
    storage_t tail;
    int size;
    
    /**** Constructors ******/
    LinkedList();
    LinkedList(suit_t s, rank_t r);
    LinkedList(LinkedList * a);
    ~LinkedList();
    
    /***** Methods ******/
    void pushFront(suit_t s, rank_t r);
    void pushBack(suit_t s, rank_t r);
    Card * popFront();
    Card * popBack();
    Card * findCardByValue(suit_t, rank_t r);
    int removeCardsByValue(suit_t s, rank_t r);
    void print();
    void concatenate(LinkedList * a);
    void safeHeadTailRemove(Card * a);
    static void countInstantiations();
    //void removeDuplicates();
    //LinkedList * subtract(LinkedList * a);
    //static LinkedList * join(LinkedList * a, LinkedList * b);

};


#endif /* defined(__LinkedList__LinkedList__) */
