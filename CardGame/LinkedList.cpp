//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include "LinkedList.h"

int LinkedList::s_count = 0;

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
    s_count++;
}

LinkedList::LinkedList(rank_t r, suit_t s) {
    storage_t n = new Card(r, s);
    head = n;
    tail = n;
    size = 1;
    s_count++;
}

LinkedList::LinkedList(LinkedList * a) {
    storage_t index = a->head;
    storage_t n = new Card(index->getRank(),index->getSuit());
    head = n;
    tail = n;
    size = 1;
    while ((index->getNext()) != NULL) {
        index = index->getNext();
        Card::join(tail,new Card(index->getRank(),index->getSuit()));
        tail = tail->getNext();
        size++;
    }
    s_count++;
}

LinkedList::~LinkedList() {
    s_count--;
}

void LinkedList::pushFront(rank_t r, suit_t s) {
    storage_t newHead = new Card(r, s);
    Card::join(newHead, this->head);
    this->head = newHead;
    size++;
}

void LinkedList::pushBack(rank_t r, suit_t s) {
    storage_t newTail = new Card(r, s);
    Card::join(this->tail, newTail);
    this->tail = newTail;
    size++;
}

//prob a bug here if it removes the head
void LinkedList::removeCardsByValue(rank_t r, suit_t s) {
    storage_t check = this->head;
    while (check != NULL) {
        storage_t temp = check->getNext();
        if(check->checkSuitRank(s,r)) {
            check->remove();
            size--;
        }
        check = temp;
    }
}

void LinkedList::print() {
    cout << "print out linked list" << endl;
    storage_t print = this->head;
    cout << print->getRank() << print->getSuit() << endl;
    while (print->getNext() != NULL) {
        print = print->getNext();
        cout << print->getRank() << print->getSuit() << endl;
    }
    cout << "end print" << endl;
}
 
/*
 Concatenates a deep copy of paramter 'a' onto calling object
 */
void LinkedList::concatenate(LinkedList * a) {
    Card::join(this->tail, a->head);
    this->tail = a->tail;
}
/* static */
void LinkedList::countInstantiations() {
    cout << "There is/are " << s_count << " Linked List Instantiation(s)" << endl;
}


/*
void LinkedList::removeDuplicates() {
    storage_t current = this->head;
    while (current->getNode()->getNextNode() != NULL) {
        storage_t index = current;
        while (index->getNode()->getNextNode() != NULL) {
            index->setNode(index->getNode()->getNextNode());
            if(current->getNode()->getValue() == index->getNode()->getValue()) {
                index->getNode()->remove();
                //Node::join(index->getNode()->getPrevNode(), index->getNode()->getNextNode());
                //delete(index);
            }
        }
        //need this check incase the nested while loop deleted the node after current and current is now then end of the list
        if(current->getNode()->getNextNode() != NULL) {
            current->setNode(current->getNode()->getNextNode());
        }
    }
}
 */

/* unnecessary
LinkedList * LinkedList::subtract(LinkedList * a) {
    LinkedList * result = new LinkedList(this);
    storage_t current = result->head;
    while (current->getNode()->getNextNode() != NULL) {
        storage_t index = a->head;
        do {
            storage_t temp = new Card(index->getNode()->getNextNode());
            if(current->getNode()->getValue() == index->getNode()->getValue()) {
                Node::join(current->getNode()->getPrevNode(), current->getNode()->getNextNode());
                delete(index);
            }
            if (temp != NULL) {
                index = temp;
            }
        } while (index->getNode()->getNextNode() != NULL);
        current->setNode(current->getNode()->getNextNode());
    }
    return result;
}
*/

/* don't need
 LinkedList * LinkedList::join(LinkedList * a, LinkedList * b) {
 LinkedList * deepCopyA = new LinkedList(a);
 deepCopyA->concatenate(new LinkedList(b));
 return deepCopyA;
 }
 */