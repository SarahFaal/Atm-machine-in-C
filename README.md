# Atm-machine-in-C
Overview
This program is a console-based ATM system implemented in C. It simulates basic banking functionalities, such as password changes, money transfers, balance updates, and account status checks. It also reads and writes account information to a file (acc.txt) for persistence.

Features
Login System
Users log in using an account number and password.

Menu Options
After logging in, users can:

Change their password.
Transfer money to another account.
Deposit or withdraw cash.
Check their account balance (with a $1 fee applied).
Save changes and quit.
View account status for debugging purposes.
Persistent Data Storage

Account information (account numbers, passwords, and balances) is stored in a file (acc.txt) and is updated automatically when changes are made.
How It Works
Data Handling

Account data is read from acc.txt on startup. The file contains data in a specific format separated by hyphens (-).
The first 10 entries are account IDs, the next 10 are passwords, and the last 10 are account balances.
Login Validation

Users are authenticated by comparing input credentials with the data loaded from the file.
Menu Options

Users are presented with a menu for available operations after successful login.
Each operation modifies the in-memory data, and changes are written back to the file when the user chooses to save and quit.
File Writing

The updated data is serialized back into the acc.txt file to maintain account consistency across sessions.
File Format: acc.txt
The acc.txt file must follow this format:

Copy code
accountID1-accountID2-...-password1-password2-...-balance1-balance2-...
Example
yaml
Copy code
1001-1002-1003-...-1234-5678-9101-...-500-1000-1500-...
How to Run
Compile the Program
Use the GCC compiler to compile the code:

bash
Copy code
gcc atm.c -o atm
Run the Program
Execute the compiled program:

bash
Copy code
./atm
Initial Setup
Ensure acc.txt exists in the program's directory and follows the expected format.

Dependencies
C Standard Library
Functions from <stdio.h>, <stdlib.h>, <string.h> are used.

System Commands
The system("cls") and system("clear") commands are used to clear the console (replace cls with clear for Linux).
