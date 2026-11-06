#pragma once
#include <string>

struct Transaction{
    std::string category;
    std::string name;
    double amount;
    std::string date;
};

class User{
private:
    std::string username;
    std::string password;
    std::string trname;
public:
    int choice = 0;
    void setUsername(std::string uname){ username = uname;}
    void setPassword(std::string pword){ password = pword; }
    void setTrname(std::string tname){ trname = tname; }
    const std::string& getUsername() const{ return username; }
    const std::string& getPassword() const{ return password; }
    const std::string& getTrname() const{ return trname; }
};

bool authorization(User &user);