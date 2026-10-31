#include <iostream>
#include <string>
#include <fstream>
#include "track.h"
using namespace std;

int main(){

    User user;
    if(!authorization(user)){
        cout << "Authorization failed" << endl;
        return 0;
    }

    menu(user);

    return 0;
}