# Simple Budgeting System In C

## Table of Contents 
1. [Description](#description)
2. [Features](#features)
3. [Installation](#installation)
4. [Program Flow](#program-flow)

## Description
- This is a simple budgeting system program written in C, utilizing standard input and output functions with a menu-driven interface for interacting with the system. 
- The program allows users to manage their finances by performing basic budgeting operations by performing basic budgeting operations such as creating an account, logging in, updating their budget, and maintaining their transaction history. Below is a brief overview of the program's features and capabilities.

## Features:
- **Add Money To Debit Account**: 
    - Allows users to add money into their debit account, this increases their debit balance.
- **Spend Money From Debit Account**: 
    - Allows users to spend money from their debit account, this decreases their debit balance.
- **Check Debit Account Balance**:
    - Allows users to view the current balance of their debit account. 
- **Spend Money From Credit Account**:
    - Allows users to spend money from their credit account, this increases their credit balance.
- **Pay Off Credit Debt**:
    - Allows users to pay off the outstanding balance on their credit account.
- **Check Credit Account Balance**:
    - Allows users to view the current balance of their credit account.
- **Display Transaction History**:
    - Displays a list of all past transactions.
- **Set New Budget**:
    - Allows users to set a new monthly spending budget.
- **Display Budget**:
    - Displays the current monthly spending budget set by the user.

## Installation
Follow the steps below to install and run the budgeting system locally:

1. Ensure that the following software are installed:
    - C compiler
    - Make

2. Clone the repository using Git:
    ```bash
    git clone https://github.com/Sam-Scott-McMaster/the-team-assignment-team-1-the-codefathers
    ```
3. Compile the program using a make:
    - To compile the program, run:
        ```bash
        make
        ```
    - **Optional**: If you want to remove the compiled files, run:
        ```bash
        make clean
        ```
4. Run the compiled program:
    ```bash
    ./budget_system
    ```
5. Follow the on-screen prompts to interact with the budgeting system


## Program Flow

### 1. **Program Start**
- A welcome message is displayed: **"Welcome To The Codefathers Budgeting System!"**.

### 2. **User Account Login/Create New Account**
- **Prompt for Username:**
    - The user is prompted to enter their username.
    - The system checks if the entered username exists in the user database.
- **If Username Exist:**
    - The user is prompted to enter their password.
    - If the password is correct, the user is logged in and the system proceeds to the main menu.
    - If the password is incorrect, the user is prompted to try again.
- **If Username Does Not Exist:**
    - The user is informed that the username does not exist.
    - The user is prompted with two options: 
        - **Option 1**: Re-enter The Username
        - **Option 2**: Create a New Account

### 3. **Option 1: Re-enter The Username**
- If the user selects to re-enter the username, the system goes back to step 2 (User Account Login/Create New Account) to check if the username exists.

### 4. **Option 2: Create a New Account**
- If the user selects to create a new account:
    - The user is prompted to enter their personal information:
        - First name
        - Last name
        - Email account
        - Birthdate
        - Phone number
    - The user is then prompted to enter a new username and password.
    - If the username does not fit the username format or is not unique, the user is prompted to enter another username.
    - If the password does not fit the password format, the user is prompted to enter another password.
    - If the username is unique and the password fits the password format, the account is then created in the user database.
    - After account creation, the system automatically logs in the user using the newly created credentials and prompt the user to set a monthly spending budget.
    - The system then proceeds to the main menu.

### 5. **Display Main Menu**
- After successful login, the user is presented with the main menu, which includes the following options:
    1. Add Money To Debit Account
    2. Spend Money From Debit Account
    3. Check Debit Account Balance
    4. Spend Money From Credit Account
    5. Pay Off Credit Debt
    6. Check Credit Account Balance
    7. Display Transaction History
    8. Set New Budget
    9. Display Budget
- After each opertaion, the system will prompt the user with a message asking if they would like to perform another transaction. If the user enters 'Y' or 'y', the system will return to the main menu. If the user presses any other key, the system will exit.
