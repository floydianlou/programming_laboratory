//
// Created by alice on 02/07/20.
//

#include <iostream>
#include "ProgramManager.h"

void ProgramManager::addUser(User &newUser) {
    allUsers.insert(std::make_pair(newUser.getRealName(), &newUser));
}


bool ProgramManager::isUsernameInList(const std::string& username) {
    auto itr = allUsers.find(username);
    if (itr != allUsers.end()) {
        currentUser = itr->second;
        return true;
    } else {
        auto newUser = new User(username);
        addUser(*newUser);
        currentUser = newUser;
        return false;
    }
}

ProgramManager::~ProgramManager() {

}

User& ProgramManager::getCurrentUser() const {
    return *currentUser;
}

time_t ProgramManager::getCurrentTime() const {
    return currentTime;
}

