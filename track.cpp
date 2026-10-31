#include <iostream>
#include <string>
#include <fstream>
#include "track.h"
using namespace std;

//Menu
void menu(User &user){
    while(1){
        // Create a file for the user's transactions
        Transaction t;
        user.trname = user.username + "_transactions.txt";

        cout << "Menu:\n1.add transaction\n2.add income\n3.view transactions\n4.statistics\n5. exit" << endl;
        cin >> user.choice;
        switch(user.choice){
            // Add transaction
            case 1: if(!add_transaction(t, user))
                        cout << "Failed to add transaction" << endl;
                    break;

            // Add income
            case 2: if(!add_income(t, user))
                        cout << "Failed to add income" << endl;
                    break;

            // View transactions
            case 3: if(!view_transactions(user))
                        cout << "Failed to view transactions" << endl;
                    break;

            // Statistics
            case 4: if(!statistics(t, user))
                        cout << "Failed to view statistics" << endl;
                    break;

            // Exit
            case 5: cout << "exit" << endl;
                    return;

            default: cout << "invalid choice" << endl;
                    break;
        }
    }
}

bool add_transaction(Transaction &t, User &user){
        cout << "Add transaction" << endl;
        cout << "Enter transaction: " << endl;
        cout << "Choose category: \n1. Food\n2. Transport\n3. Entertainment\n4. Other" << endl;
        cin >> user.choice;

        switch(user.choice){
            case 1:
                t.category = "Food";
                break;
            case 2:
                t.category = "Transport";
                break;
            case 3:
                t.category = "Entertainment";
                break;
            case 4:
                t.category = "Other";
                break;
            default:
                cout << "invalid choice" << endl;
                return false;
        }
        cout << "Enter name of transaction: " << endl;
        cin >> t.name;

        cout << "Enter amount: " << endl;
        cin >> t.amount;

        cout << "Enter date (dd/mm/yyyy): " << endl;
        cin >> t.date;


        ofstream f3;
        f3.open(user.trname, ios::app);

        if(f3.fail()){
            return false;
        }

        string transaction = t.category + ' ' + t.name + ' ' + to_string(t.amount) + ' ' + t.date;
        
        f3 << transaction << endl;
        f3.close();

        return true;
 }

 bool add_income(Transaction &t, User &user){
    cout << "Add income" << endl;
    cout << "Enter name of income: " << endl;
    cin >> t.name;

    cout << "Enter amount: " << endl;
    cin >> t.amount;

    cout << "Enter date (dd/mm/yyyy): " << endl;
    cin >> t.date;

    ofstream f4;

    f4.open(user.trname, ios::app);

    if(f4.fail()){
        return false;
    }

    string income_transaction = "Income " + t.name + ' ' + to_string(t.amount) + ' ' + t.date;

    f4 << income_transaction << endl;
    f4.close();

    return true;
 }

 bool view_transactions(User &user){
    ifstream f5;
    f5.open(user.trname, ios::in);

    if(f5.fail()){
        return false;
    }

    cout << "\t---Your last 10 transactions---" << endl;
    int count = 0;

    while(!f5.eof()){
        string temp;
        getline(f5, temp);
        cout << temp << endl;

        count++;
        if(count == 10){
            break;
        }
    }
    cout << "\n";

    f5.close();
    return true;

 }

 bool statistics(Transaction &t, User &user){
    cout << "\t---Statistics---" << endl;
    ifstream f6;
    f6.open(user.trname, ios::in);

    if(f6.fail()){
        return false;
    }

    double total_income = 0;
    double total_expense = 0;
    double max_expense = 0;
    double average_expense = 0;
    int count = 0;


    while(!f6.eof()){
        string temp;
        while (f6 >> t.category >> t.name >> t.amount >> t.date) {
            if (t.category == "Income") {
            total_income += t.amount;
            } 

            else {
                total_expense += t.amount;
                if (t.amount > max_expense) {
                    max_expense = t.amount;
                }
                count++;
            }
        }
    }

    if (count > 0) {
        average_expense = total_expense / count;
    }

    
    cout << "\tTotal income: " << total_income << endl;
    cout << "\tTotal expense: " << total_expense << endl;
    cout << "\tMaximum expense: " << max_expense << "\n" << endl;
    cout << "\tAverage expense: " << average_expense << "\n" << endl;

    f6.close();

    return true;
 }