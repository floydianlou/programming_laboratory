//
// Created by alice on 02/07/20.
//


#include <iostream>
#include "Chat.h"

Chat::Chat(const User &sender, const User &receiver, std::string name) : senderName(sender.getRealName()),
                                                                         receiverName(receiver.getRealName()),
                                                                         chatName(std::move(name)) {}

void Chat::addMessage(Message &text) {
    if ((text.getSenderName() == senderName || text.getSenderName() == receiverName) &&
        (text.getReceiverName() == receiverName || text.getReceiverName() == senderName)) {
        chatMessages.insert(std::make_pair(text.getMessageId(), &text));
    } else {
        throw std::invalid_argument("Sender or receiver don't match.");
    }
}

void Chat::deleteMessage(int ID) {
    auto found = chatMessages.find(ID);
    if(chatMessages.size() == 1) {
        throw std::invalid_argument ("You can't delete the last message of a chat!");
    }
    if (found != chatMessages.end()) {
        chatMessages.erase(found);
    } else {
        throw std::out_of_range("No message with such ID.");
    }
}

std::_Rb_tree_iterator<std::pair<const int, Message *>> Chat::openMessage() {
    for (auto &chatMessage : chatMessages) {
        if (!chatMessage.second->isRead()) {
            chatMessage.second->setRead(true);
        }
    }
    return chatMessages.begin();
}

int Chat::numOfUnreadMessages() const {
    int count = 0;
    for (auto itr: chatMessages) {
        if (!itr.second->isRead()) {
            count++;
        }
    }
    return count;
}

std::string Chat::getSenderName() const {
    return senderName;
}

std::string Chat::getReceiverName() const {
    return receiverName;
}

std::string Chat::getChatName() const {
    return chatName;
}

Chat::~Chat() {

}

