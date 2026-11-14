#include <iostream>
#include <string>
#include <fstream>
#include "track.h"

int main(){

    User user;
    if(!authorization(user)){
        std::cout << "Authorization failed" << std::endl;
        return 0;
    }

    menu(user);

    return 0;
}