# Simple Budgeting System in C

This is a simple budegting system program written in C. It allows users to manage their finances by performing basic budgeting operations such as tracking income, recording expenses, and keeping track of transaction history. Below is a breif overview of the program and its functionalities.

## Program Overview

- This program is written in C and uses standard input and output functions, featuring a menu-driven interface for interacting with the system.
- It simulates a budgeting system where users can create an account, log in, update their budget, and track their transaction history. 
- Users can perform the following operations:
    - Create new account 
    - Login to existing account
    - View transaction history
    - Add money to debit account
    - Spend money from debit account
    - Check debit account balance
    - Spend money from credit account
    - Pay off credit debt
    - Check credit account balance

## Getting Started

1. Compile the program using a C compiler:
    ```bash
    gcc -o budget_system main.c 
2. Run the compiled program:
    ```bash
    ./budget_system
3. Follow the on-screen prompts to interact with the budgeting system

## Program Flow

- When you run the program, a welcome message will be displayed, and you will be prompted to either login or create a new account.
    - If you choose to create a new account, the program will request you to enter your personal informations including your name, email address, phone number, date of birth. Additionally, you will be prompted to set a username and password.
    - If you choose to log in, the program will prompt you to enter your username and password to access your account.
- Once you successfully access your account, you can choose from the following options:
    1. Add Money To Debit Account
    2. Spend Money From Debit Account
    3. Check Debit Account Balance
    4. Spend Money From Credit Account
    5. Pay Off Credit Debt
    6. Check Credit Account Balance
    7. Exit
- After each opertaion, the program will ask if you want to perform another transaction. If yes, enter 'Y' or 'y' to continue. If no, press any other key to exit.
