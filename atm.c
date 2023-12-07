#include <stdio.h>
#include <string.h>
void main() {
//Banking Application for atm
    int pin = 3333 , pin1, c = 1, amt, ch, balance = 5000;
    char input[50];
    start:
    while (1) {
        printf("\n         ???Welcome to State Bank Of India???\n");
       
        printf("Enter your pin Number or 'stop' to exit: \n");
        scanf("%s", input);

        if (strcmp(input, "stop") == 0) {
            printf("Exiting...\n");
            break; 
        }

        sscanf(input, "%d", &pin1);

        if (pin == pin1) {
            while (1) {
                printf(" 1. Deposit\n 2. Withdraw\n 3. Check Balance\n 4. Change Pin\n 5. Exit\n");
                printf("Enter your choice above \nor'continue' to go back to the main menu:\n");
                scanf("%s", input);

                if (strcmp(input, "continue") == 0) {
                    break; // Exit the inner loop and go back to the main menu
                }

                sscanf(input, "%d", &ch);

                switch (ch) {
                    case 1:
                        printf("Enter your deposit amount:\n");
                        scanf("%d", &amt);
                        if (amt <= 20000) {
                            balance += amt;
                            printf("Balance: %d\n\n", balance);
                        } else {
                            printf("Max limit for deposit is 20k\n");
                        }
                        break;

                    case 2:
                        printf("Enter your withdrawal amount:\n");
                        scanf("%d", &amt);
                        if (amt <= 20000) {
                            if (amt <= balance) {
                                balance -= amt;
                                printf("After deducting %d, Current balance = %d\n\n", amt, balance);
                            } else {
                                printf("Insufficient balance try again...!\n");
                            }
                        } else {
                            printf("Max limit for withdrawal is 20k\n");
                        }
                        break;

                    case 3:
                        printf("Current balance = %d\n", balance);
                        break;

                    case 4:
                        printf("Enter new pin number: ");
                        scanf("%d", &pin);
                        int confirmpin;
                        printf("Confirm your new pin :");
                        scanf("%d",& confirmpin);
                        if(pin=confirmpin){
                        printf("Your pin has been updated successfully. Login again\n");
                        }
                        goto start;
                        break;

                    case 5:
                        printf("Exiting...\n");
                        return 0;

                    default:
                        printf("Invalid choice\n");
                }
            }
        } else {
            printf("Please Enter a valid pin\n");
            if (c < 3) {
                c++;
                goto start ; 
            } else {
                printf("Too many incorrect attempts. Exiting.\n");
                return 0;
            }
        }
    }

}

