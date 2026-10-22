#include <stdio.h>
#include <stdlib.h>

void show_menu() {
    printf("\n========================================\n");
    printf("         GLOBAL BANK SERVICES           \n");
    printf("========================================\n");
    printf("  [1] Check Balance                     \n");
    printf("  [2] Deposit Money                     \n");
    printf("  [3] Withdraw Money                    \n");
    printf("  [4] Mini Statement / Summary          \n");
    printf("  [5] Exit                              \n");
    printf("========================================\n");
    printf("Enter your choice (1-5): ");
}

int main() {
    int choice;
    double balance = 5000.00;
    double amount;

    while (1) {
        show_menu();

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Numbers only.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nCurrent Available Balance: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: Rs. ");
                scanf("%lf", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Successfully deposited Rs. %.2f\n", amount);
                    printf("Updated Balance: Rs. %.2f\n", balance);
                } else {
                    printf("Deposit amount must be greater than 0.\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: Rs. ");
                scanf("%lf", &amount);
                if (amount <= 0) {
                    printf("Amount must be positive.\n");
                } else if (amount > balance) {
                    printf("Insufficient funds! Available balance: Rs. %.2f\n", balance);
                } else {
                    balance -= amount;
                    printf("Withdrawal successful: Rs. %.2f\n", amount);
                    printf("Remaining Balance: Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("\n--- ACCOUNT OVERVIEW ---\n");
                printf("Status  : Active\n");
                printf("Currency: INR\n");
                printf("Balance : Rs. %.2f\n", balance);
                printf("------------------------\n");
                break;

            case 5:
                printf("\nThank you for banking with us.\n\n");
                exit(0);

            default:
                printf("\nInvalid selection! Pick an option from 1 to 5.\n");
        }
    }

    return 0;
}
