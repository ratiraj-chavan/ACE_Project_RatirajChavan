#include <stdio.h>
#include <stdlib.h>
// Function declarations
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    float balance = 10000.0; // Initial balance
    int choice;

    printf("Welcome to the ATM Simulation Program\n");

    do { // Menu
        printf("\n=========== ATM MENU ===========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
      } while(choice != 4);
     return 0;
}

// Function to check balance
void checkBalance(float balance) {
    printf("Your current balance is: ₹%.2f\n", balance);
}

// Function to deposit money
float depositMoney(float balance) {
    float deposit;
    printf("Enter amount to deposit: ₹");
    scanf("%f", &deposit);

    if (deposit <= 0) {
        printf("Invalid deposit amount.\n");
    } else {
        balance += deposit;
        printf("₹%.2f deposited successfully.\n", deposit);
        printf("Updated balance: ₹%.2f\n", balance);
    }
    return balance;
}

// Function to withdraw money
float withdrawMoney(float balance) {
    float withdraw;
    printf("Enter amount to withdraw: ₹");
    scanf("%f", &withdraw);

    if (withdraw <= 0) {
        printf("Invalid withdrawal amount.\n");
    } else if (withdraw > balance) {
        printf("Insufficient balance. Transaction failed.\n");
    } else {
        balance -= withdraw;
        printf("₹%.2f withdrawn successfully.\n", withdraw);
        printf("Updated balance: ₹%.2f\n", balance);
    }
    return balance;
}