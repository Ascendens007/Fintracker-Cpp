#include <iostream>
#include <string>
#include <fstream>
#include "track.h"

//Menu
void menu(User &user){
    while(1){
        // Create a file for the user's transactions
        Transaction t;
        user.setTrname(user.getUsername() + "_transactions.txt");

        std::cout << "Menu:\n1.add transaction\n2.add income\n3.view transactions\n4.statistics\n5. exit" << std::endl;

        std::cin >> user.choice;

        switch(user.choice){
            // Add transaction
            case 1: if(!add_transaction(t, user))
                        std::cout << "Failed to add transaction" << std::endl;
                    break;

            // Add income
            case 2: if(!add_income(t, user))
                        std::cout << "Failed to add income" << std::endl;
                    break;

            // View transactions
            case 3: if(!view_transactions(user))
                        std::cout << "Failed to view transactions" << std::endl;
                    break;

            // Statistics
            case 4: if(!statistics(t, user))
                        std::cout << "Failed to view statistics" << std::endl;
                    break;

            // Exit
            case 5: std::cout << "exit" << std::endl;
                    return;

            default: std::cout << "invalid choice" << std::endl;
                    break;
        }
    }
}

bool add_transaction(Transaction &t, User &user){
        std::cout << "Add transaction" << std::endl;
        std::cout << "Enter transaction: " << std::endl;
        std::cout << "Choose category: \n1. Food\n2. Transport\n3. Entertainment\n4. Other" << std::endl;
        std::cin >> user.choice;

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
                std::cout << "invalid choice" << std::endl;
                return false;
        }
        std::cout << "Enter name of transaction: " << std::endl;
        std::cin >> t.name;

        std::cout << "Enter amount: " << std::endl;
        std::cin >> t.amount;

        std::cout << "Enter date (dd/mm/yyyy): " << std::endl;
        std::cin >> t.date;


        std::ofstream f3;
        f3.open(user.getTrname(), std::ios::app);

        if(f3.fail()){
            return false;
        }

        std::string transaction = t.category + ' ' + t.name + ' ' + std::to_string(t.amount) + ' ' + t.date;
        
        f3 << transaction << std::endl;
        f3.close();

        return true;
 }

 bool add_income(Transaction &t, User &user){
    std::cout << "Add income" << std::endl;
    std::cout << "Enter name of income: " << std::endl;
    std::cin >> t.name;

    std::cout << "Enter amount: " << std::endl;
    std::cin >> t.amount;

    std::cout << "Enter date (dd/mm/yyyy): " << std::endl;
    std::cin >> t.date;

    std::ofstream f4;

    f4.open(user.getTrname(), std::ios::app);

    if(f4.fail()){
        return false;
    }

    std::string income_transaction = "Income " + t.name + ' ' + std::to_string(t.amount) + ' ' + t.date;

    f4 << income_transaction << std::endl;
    f4.close();

    return true;
 }

 bool view_transactions(User &user){
    std::ifstream f5;
    f5.open(user.getTrname(), std::ios::in);

    if(f5.fail()){
        return false;
    }

    std::cout << "\t---Your last 10 transactions---" << std::endl;
    int count = 0;

    while(!f5.eof()){
        std::string temp;
        getline(f5, temp);
        std::cout << temp << std::endl;

        count++;
        if(count == 10){
            break;
        }
    }
    std::cout << "\n";

    f5.close();
    return true;

 }

 bool statistics(Transaction &t, User &user){
    std::cout << "\t---Statistics---" << std::endl;
    std::ifstream f6;
    f6.open(user.getTrname(), std::ios::in);

    if(f6.fail()){
        return false;
    }

    double total_income = 0;
    double total_expense = 0;
    double max_expense = 0;
    double average_expense = 0;
    int count = 0;


    while(!f6.eof()){
        std::string temp;
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

    
    std::cout << "\tTotal income: " << total_income << std::endl;
    std::cout << "\tTotal expense: " << total_expense << std::endl;
    std::cout << "\tMaximum expense: " << max_expense << "\n" << std::endl;
    std::cout << "\tAverage expense: " << average_expense << "\n" << std::endl;

    f6.close();

    return true;
 }