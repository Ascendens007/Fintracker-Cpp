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
        cout << "Enter your username: " << endl;
        cin >> user.username;
        ifstream f;
        f.open("usernames.txt", ios::in);

        if(f.is_open()){
            while(!f.eof()){
                string temp;
                getline(f, temp);
                erase(temp, '\n');
                if(temp == user.username){
                    cout << "That username exist" << endl;
                    return false;
                }
            }
            f.close();
        }
        
        cout << "Enter your password: " << endl;
        cin >> user.password;

        cout << "confirm your password: " << endl;
        string password2;

        cin >> password2;
        if(user.password != password2){
            cout << "Passwords do not match" << endl;
            return false;
        }

        ofstream f1;
        f1.open("usernames.txt", ios::app);

        if(f1.fail()){
            return false;
        }
        f1 << user.username << endl;
        f1.close();

        ofstream f2;
        f2.open("passwords.txt", ios::app);

        if(f2.fail()){
            return false;
        }

        user.password = user.username + ' ' + user.password;
        f2 << user.password << endl;

        f2.close();

        user.choice = 1;

        cout << "You are signed up!" << endl;
    }

    // Log in
    if(user.choice == 1){
        cout << "Hello, enter your credits:" << endl;

        cout << "Your username: ";
        cin >> user.username;
        erase(user.username, '\n');
        ifstream f;
        f.open("usernames.txt");

        if(f.fail()){
            return false;
        }

        int flag = 0;

        while(!f.eof()){
            string temp;
            getline(f, temp);
            if(user.username == temp){
                flag = 1;
            }
        }

        f.close();

        if(flag == 0){
            cout << "That username doesn't exist" << endl;
            return false;
        }

        else{
            cout << "Your password: " << endl;
            cin >> user.password;
        }
            erase(user.password, '\n');

            user.password = user.username + ' ' + user.password;

            ifstream f2;
            f2.open("passwords.txt");
            int flag2 = 0;

            while(!f2.eof()){
                string temp;
                getline(f2, temp);
                if(user.password == temp){
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
                cout << "Welcome, " << user.username << endl;
            }

            return true;
        }
        return false;
 }