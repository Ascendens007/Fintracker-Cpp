# Personal Finance Tracker (C++)

A modular console-based personal finance management application written in C++ (C++20). The application allows users to securely register and log in, record incomes and categorized expenses, view transaction history, and inspect calculated financial statistics.

---

## Features

- **User Authentication**: Secure sign-up and login mechanism verifying stored credentials.
- **Transaction Management**:
  - Add expense records categorized by type (Food, Transport, Entertainment, Other).
  - Record income entries.
  - Per-user transaction logging into dedicated files (`<username>_transactions.txt`).
- **History & Reports**:
  - View up to 10 latest logged operations.
  - View overall financial statistics: total income, total expense, and peak single expense.
- **Modular Code Architecture**: Clean separation into headers and translation units (`models.h`, `track.h`, `auth.cpp`, `track.cpp`, `main.cpp`).

---

## Project Structure

```text
├── models.h        # Shared data structures (User, Transaction) and declarations
├── track.h         # Financial tracking interface and prototypes
├── auth.cpp        # Authentication workflow (sign-up, login, data sanitization)
├── track.cpp       # Core transactions, file I/O operations, and statistics logic
├── main.cpp        # Application entry point and interactive menu loop
└── README.md       # Project overview and documentation