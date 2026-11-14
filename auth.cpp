#include <fstream>
#include <iostream>
#include <string>
#include "models.h"

bool authorization(User &user){

    do{
    std::cout << "1. log in\n2. sign up" << std::endl;
    std::cin >> user.choice;

    } while(user.choice < 1 || user.choice > 2);

    // Sign up
    if(user.choice == 2){
        std::string* newuser = new std::string[2];

        std::cout << "Enter your username: " << std::endl;
        std::cin >> newuser[0];
        user.setUsername(newuser[0]);
        std::ifstream f;
        f.open("usernames.txt", std::ios::in);

        if(f.is_open()){
            while(!f.eof()){
                std::string temp;
                std::getline(f, temp);
                if(temp == user.getUsername()){
                    std::cout << "That username exist" << std::endl;

                    delete[] newuser;
                    newuser = nullptr;

                    return false;
                }
            }
            f.close();
        }
        
        std::cout << "Enter your password: " << std::endl;
        std::cin >> newuser[1];
        user.setPassword(newuser[1]);
        
        delete[] newuser;
        newuser = nullptr;

        std::cout << "confirm your password: " << std::endl;
        std::string* password2 = new std::string;

        std::cin >> *password2;
        if(user.getPassword() != *password2){
            std::cout << "Passwords do not match" << std::endl;
            
            delete password2;
            password2 = nullptr;

            return false;
        }

        delete password2;
        password2 = nullptr;

        std::ofstream f1;
        f1.open("usernames.txt", std::ios::app);

        if(f1.fail()){
            return false;
        }
        f1 << user.getUsername() << std::endl;
        f1.close();

        std::ofstream f2;
        f2.open("passwords.txt", std::ios::app);

        if(f2.fail()){
            return false;
        }

        user.setPassword(user.getUsername() + ' ' + user.getPassword());
        f2 << user.getPassword() << std::endl;

        f2.close();

        user.choice = 1;

        std::cout << "You are signed up!" << std::endl;
    }

    // Log in
    if(user.choice == 1){
        std::string* userpass = new std::string[2];
        std::cout << "Hello, enter your credits:" << std::endl;

        std::cout << "Your username: ";
        std::cin >> userpass[0];
        user.setUsername(userpass[0]);

        std::ifstream f;
        f.open("usernames.txt");

        if(f.fail()){
            delete[] userpass;
            userpass = nullptr;
            return false;
        }

        int flag = 0;

        while(!f.eof()){
            std::string temp;
            std::getline(f, temp);
            if(user.getUsername() == temp){
                flag = 1;
            }
        }

        f.close();

        if(flag == 0){
            std::cout << "That username doesn't exist" << std::endl;
            
            delete[] userpass;
            userpass = nullptr;
            
            return false;
        }

        else{
            std::cout << "Your password: " << std::endl;
            std::cin >> userpass[1];
            user.setPassword(userpass[1]);
        }
        
        delete[] userpass;
        userpass = nullptr;

        user.setPassword(user.getUsername() + ' ' + user.getPassword());

        std::ifstream f2;
        f2.open("passwords.txt");
        int flag2 = 0;

        while(!f2.eof()){
            std::string temp;
            std::getline(f2, temp);
            if(user.getPassword() == temp){
                flag2 = 1;
            }
        }
        
        f2.close();
        if(flag2 == 0){
            std::cout << "That password is incorrect" << std::endl;
            return false;
        }

        else{
            std::cout << "You are logged in!" << std::endl;
            std::cout << "Welcome, " << user.getUsername() << std::endl;
        }

        return true;
    }
    return false;
 }