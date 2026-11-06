#include <fstream>
#include <iostream>
#include <string>
#include "models.h"
using namespace std;

bool authorization(User &user){

    do{
    cout << "1. log in\n2. sign up" << endl;
    cin >> user.choice;

    } while(user.choice < 1 || user.choice > 2);

    // Sign up
    if(user.choice == 2){
        string* newuser = new string[2];

        cout << "Enter your username: " << endl;
        cin >> newuser[0];
        user.setUsername(newuser[0]);
        ifstream f;
        f.open("usernames.txt", ios::in);

        if(f.is_open()){
            while(!f.eof()){
                string temp;
                getline(f, temp);
                if(temp == user.getUsername()){
                    cout << "That username exist" << endl;

                    delete[] newuser;
                    newuser = nullptr;

                    return false;
                }
            }
            f.close();
        }
        
        cout << "Enter your password: " << endl;
        cin >> newuser[1];
        user.setPassword(newuser[1]);
        
        delete[] newuser;
        newuser = nullptr;

        cout << "confirm your password: " << endl;
        string* password2 = new string;

        cin >> *password2;
        if(user.getPassword() != *password2){
            cout << "Passwords do not match" << endl;
            
            delete password2;
            password2 = nullptr;

            return false;
        }

        delete password2;
        password2 = nullptr;

        ofstream f1;
        f1.open("usernames.txt", ios::app);

        if(f1.fail()){
            return false;
        }
        f1 << user.getUsername() << endl;
        f1.close();

        ofstream f2;
        f2.open("passwords.txt", ios::app);

        if(f2.fail()){
            return false;
        }

        user.setPassword(user.getUsername() + ' ' + user.getPassword());
        f2 << user.getPassword() << endl;

        f2.close();

        user.choice = 1;

        cout << "You are signed up!" << endl;
    }

    // Log in
    if(user.choice == 1){
        string* userpass = new string[2];
        cout << "Hello, enter your credits:" << endl;

        cout << "Your username: ";
        cin >> userpass[0];
        user.setUsername(userpass[0]);

        ifstream f;
        f.open("usernames.txt");

        if(f.fail()){
            delete[] userpass;
            userpass = nullptr;
            return false;
        }

        int flag = 0;

        while(!f.eof()){
            string temp;
            getline(f, temp);
            if(user.getUsername() == temp){
                flag = 1;
            }
        }

        f.close();

        if(flag == 0){
            cout << "That username doesn't exist" << endl;
            
            delete[] userpass;
            userpass = nullptr;
            
            return false;
        }

        else{
            cout << "Your password: " << endl;
            cin >> userpass[1];
            user.setPassword(userpass[1]);
        }
        
        delete[] userpass;
        userpass = nullptr;

        user.setPassword(user.getUsername() + ' ' + user.getPassword());

        ifstream f2;
        f2.open("passwords.txt");
        int flag2 = 0;

        while(!f2.eof()){
            string temp;
            getline(f2, temp);
            if(user.getPassword() == temp){
                flag2 = 1;
            }
        }
        
        f2.close();
        if(flag2 == 0){
            cout << "That password is incorrect" << endl;
            return false;
        }

        else{
            cout << "You are logged in!" << endl;
            cout << "Welcome, " << user.getUsername() << endl;
        }

        return true;
    }
    return false;
 }