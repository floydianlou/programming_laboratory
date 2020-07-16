//
// Created by alice on 02/07/20.
//

#ifndef PROGRAMMING_LAB_CHAT_H
#define PROGRAMMING_LAB_CHAT_H

#include <vector>
#include <map>
#include "User.h"
#include "Message.h"

class User;

class Chat {
public:

    Chat(const User &sender, const User &receiver, std::string name);

    virtual ~Chat();

    void addMessage(Message &text);


    const Message *getLastMessage() const {
        return chatMessages.rbegin()->second;
    }

    int numberOfMessages() const {
        return chatMessages.size();
    }

    int numOfUnreadMessages() const;

    std::_Rb_tree_iterator<std::pair<const int, Message *>> openMessage();

    void deleteMessage(int ID);


    std::string getSenderName() const;

    std::string getReceiverName() const;

    std::string getChatName() const;


private:
    std::map<int, Message *> chatMessages;
    std::string senderName;
    std::string receiverName;
    std::string chatName;
};

#endif //PROGRAMMING_LAB_CHAT_H
