    //
//  LinkedList.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include "LinkedList.h"



LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
    //s_count++;
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
    //s_count++;
}

LinkedList::~LinkedList() {
    //s_count--;
}

void LinkedList::pushFront(suit_t s, rank_t r) {
    storage_t newHead = new Card(r, s);
    if (isEmpty()) {
        pushToEmpty(newHead);
    }
    else {
        Card::join(this->head, newHead);
    }
    pushToEmpty(newHead);
    Card::join(newHead, this->head);
    this->head = newHead;
    size++;
}

void LinkedList::pushBack(suit_t s, rank_t r) {
    storage_t newTail = new Card(s, r);
    if (isEmpty()) {
            pushToEmpty(newTail);
    }
    else {
        Card::join(this->tail, newTail);
        this->tail = newTail;
        size++;
    }
}

void LinkedList::pushAfter(Card * target, Card * push) {
    if (target == this->tail) {
        Card::join(target, push);
        this->tail = push;
    }
    else {
        Card::join(push, target->getNext());
        Card::join(target, push);
    }
    size++;
}

void LinkedList::pushToEmpty(Card * a) {
    this->head = a;
    this->tail = a;
    size++;
}

Card * LinkedList::popFront() {
    if (this->head == NULL) {
        cout << "trying to popFront from empty list" << endl;
        exit(EXIT_SUCCESS);
    }
    Card * front = new Card(this->head->getSuit(),this->head->getRank());
    safeHeadTailRemove(this->head);
    size--;
    return front;
}

Card * LinkedList::popBack() {
    if (this->head == NULL) {
        cout << "trying to popBack from empty list" << endl;
        exit(EXIT_SUCCESS);
    }
    Card * back = new Card(this->tail->getSuit(),this->tail->getRank());
    safeHeadTailRemove(this->tail);
    size--;
    return back;
}

Card * LinkedList::findByValue(suit_t s, rank_t r) {
    storage_t check = this->head;
    while (check != NULL) {
        storage_t temp = check->getNext();
        if(check->checkSuitRank(s,r)) {
            return check;
        }
        check = temp;
    }
    return NULL;
}

//returns number of Cards removed
int LinkedList::removeByValue(suit_t s, rank_t r) {
    Card * toRemove;
    int numCardsRemoved = 0;
    while ((toRemove = findByValue(s, r)) != NULL) {
        safeHeadTailRemove(toRemove);
        size--;
        numCardsRemoved++;
    }
    return numCardsRemoved;
}

//returns the card that passed in card was moved to
Card * LinkedList::moveCardByValueDirection(Card * move, int n, int d) {
    Card * moveToAfter = getShiftedByAmountDirectionCard(move, n, d);
    //ensures that it doesn't attach a node to itself, thus avoiding disastrously incorrect loops
    if (move == moveToAfter) {
        return moveToAfter;
    }
    Card * temp = new Card(move->getSuit(), move->getRank());
    safeHeadTailRemove(move);
    size--;
    pushAfter(moveToAfter, temp);
    return moveToAfter;
}

/*****private functions ******* ******* ******* ******* ********/

Card * LinkedList::getShiftedByAmountDirectionCard(Card * start, int num, int dir) {
    Card * shifted = start;
    if (dir == 1) {
        while (num > 0 && shifted->getNext()) {
            shifted = shifted->getNext();
            num--;
        }
    }
    else if (dir == 0) {
        while (num > 0 && shifted->getPrev()) {
            shifted = shifted->getPrev();
            num--;
        }
    }
    return shifted;
}

bool LinkedList::isEmpty() {
    if (head == NULL && tail == NULL && size ==0) {
        return true;
    }
    return false;
}

void LinkedList::peekFrontAnAmount(int a) {
    cout << "peek at linkedlist, amount: " << a << endl;
    Card * show = this->head;
    for (; a > 0 && show != NULL; a--) {
        cout << "suit: " << show->getSuit() << ", rank: " << show->getRank() << endl;
        if (show->getNext() == NULL) {
            break;
        }
        show = show->getNext();
    }
    cout << "end print" << endl;
}

void LinkedList::print() {
    cout << "print out linked list" << endl;
    Card * show = this->head;
    while (show != NULL) {
        cout << "suit: " << show->getSuit() << ", rank: " << show->getRank() << endl;
        if (show->getNext() == NULL) {
            break;
        }
        show = show->getNext();
    }
    cout << "end print" << endl;
}

/*
 Concatenates a deep copy of paramter 'a' onto calling object
 */
void LinkedList::concatenate(LinkedList * a) {
    Card::join(this->tail, a->head);
    this->tail = a->tail;
    this->size = this->size + a->size;
}

void LinkedList::safeHeadTailRemove(Card * a) {
    if (this->head == a) {
        this->head = a->getNext();
    }
    if (this->tail == a) {
        this->tail = a->getPrev();
    }
    a->removeAndDelete();
}


/* static
void LinkedList::countInstantiations() {
    cout << "There is/are " << s_count << " Linked List Instantiation(s)" << endl;
}
*/

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