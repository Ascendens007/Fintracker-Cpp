#pragma once
#include "models.h"
void menu(User &user);
bool add_transaction(Transaction &t, User &user);
bool add_income(Transaction &t, User &user);
bool view_transactions(User &user);
bool statistics(Transaction &t, User &user);