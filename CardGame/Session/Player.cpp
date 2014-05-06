//
//  Player.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Player.h"

static int id_count = 1;

Player::Player() {
    money = 0;
    hand = new Hand();
    name = "";
    player_id = id_count++;
}

Player::Player(string a) {
    money = 0;
    hand = new Hand();
    name = a;
    player_id = id_count++;
}

Player::Player(string setName, money_t setMoney) {
    money = setMoney;
    hand = new Hand();
    name = setName;
    player_id = id_count++;
}


Player::~Player() {
    player_id = id_count--;
}

string Player::getName() {
    return name;
}

void Player::setMoney(money_t setMoney) {
    money = setMoney;
}

money_t Player::getMoney() {
    return money;
}

hand_t Player::getHand() {
    return hand;
}
