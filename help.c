/** 
 * Authors: Rachel Nyonje
 * Student Number: 400501476
 * Date Handed In: 05/12/2024
 * 
 * Description:
 * Provides detailed information about how to use the budgeting system. 
 * including options, features, examples, important notes and usage details.
 * 
 * Main Features:
 * - Maintaining debit and credit accounts
 * - Setting budgets
 * - Tracking transactions
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void help() {
    printf("Usage: budgeting_system [OPTIONS]\n\n");
    printf("Welcome to the Codefathers Budgeting System, a tool for managing your finances\n");
    printf("and tracking your debit and credit transactions.\n\n");
    printf("OPTIONS:\n");
    printf("    --help                  Display this help message and exit.\n");
    printf("    --version               Show the program version and exit.\n\n");
    printf("FEATURES:\n");
    printf("    This program offers the following capabilities:\n");
    printf("        - Create a new account with username, password, and personal details.\n");
    printf("        - Set and monitor your monthly spending budget.\n");
    printf("        - Manage debit and credit accounts efficiently.\n");
    printf("        - Perform a variety of transactions, such as:\n");
    printf("            1. Add Money To Debit Account\n");
    printf("            2. Spend Money From Debit Account\n");
    printf("            3. Check Debit Account Balance\n");
    printf("            4. Spend Money From Credit Account\n");
    printf("            5. Pay Off Credit Debt\n");
    printf("            6. Check Credit Account Balance\n");
    printf("            7. Display Transaction History\n");
    printf("            8. Set New Budget\n");
    printf("            9. Display Budget\n\n");
    printf("USAGE DETAILS:\n");
    printf("    On program launch:\n");
    printf("        - Existing users can log in using their username and password.\n");
    printf("        - New users will be prompted to create an account with the required details.\n\n");
    printf("EXAMPLES:\n");
    printf("    To start the program:\n");
    printf("        ./budgeting_system\n\n");
    printf("    To display the help message:\n");
    printf("        ./budgeting_system --help\n\n");
    printf("    To view the version information:\n");
    printf("        ./budgeting_system --version\n\n");
    printf("NOTES:\n");
    printf("    - Input data, such as transaction dates, must follow the format 'YYYY-MM-DD'.\n");
    printf("    - If login issues occur, recheck your username and password, or create a new account.\n\n");
    printf("For additional support, refer to the documentation or contact the Codefathers development team.\n");
}