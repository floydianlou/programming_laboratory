//
// Created by alice on 02/07/20.
//


#include <iostream>
#include "User.h"


void User::addChat(const Chat &chat) {
    chats.push_back(chat);
}

Chat &User::openAChat(int number) {
    if (number >= 0 && number < chats.size()) {
        return chats[number];
    } else {
        throw std::out_of_range("Could not find requested chat.");
    }
}

bool User::noChats() const {
    return chats.empty();
}


int User::getNumOfUnreadChats() const {
    int count = 0;
    for (const auto& itr : chats) {
        if (itr.numOfUnreadMessages() > 0) {
            count++;
        }
    }
    return count;
}