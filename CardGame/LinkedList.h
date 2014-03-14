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
    void pushAfter(Card * target, Card * push);
    void pushToEmpty(storage_t a);
    storage_t popFront();
    storage_t popBack();
    storage_t findByValue(suit_t, rank_t r);
    int removeByValue(suit_t s, rank_t r);
    storage_t moveCardByValDir(storage_t move, int n, int d);
    void print();
    void concatenate(LinkedList * a);

    
    //void removeDuplicates();
    //LinkedList * subtract(LinkedList * a);
    //static LinkedList * join(LinkedList * a, LinkedList * b);
private:
    static int s_count;
    bool isEmpty();
    storage_t getShiftedByAmountDirectionCard(storage_t start, int n, int d);

    void safeHeadTailRemove(storage_t a);
    static void countInstantiations();

};


#endif /* defined(__LinkedList__LinkedList__) */
