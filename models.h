#pragma once
#include <string>

struct Transaction{
    std::string category;
    std::string name;
    double amount;
    std::string date;
};

struct User{
    std::string username;
    std::string password;
    int choice;
    std::string trname;
};

bool authorization(User &user);