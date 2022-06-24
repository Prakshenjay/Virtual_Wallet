// Program to replicate a Virtual Wallet inteface

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // INTRODUCTION

    printf("\n***********************************************");
    printf("\n*         WELCOME TO YOUR VIRTUAL WALLET      *");
    printf("\n***********************************************\n\n");

    printf("\nPlease Log In to your account.\n");
    printf("\n1. Log In\n");
    printf("\n2. New User Account\n");
    printf("\n:");
    
    int select;
    scanf("%d", &select);

    int pin;
    char name[50];
    float balance;

    switch (select)
    {
    case 1:
        goto login;
        break;
    case 2:
        goto creation;
        break;
    }

    // New User Account Creation

creation:

    balance = 0;

    int i, j;
    do
    {
        printf("\nEnter your User name : ");
        scanf("%s", &name);
        if (1)
        {
            i = 0;
        }
        else
        {
            printf("\nYour entered USER NAME is of wrong format.\n");
            i = 1;
        }
    } while (i);

    do
    {
        printf("\nEnter a new 4 digit PIN : ");
        scanf("%d", &pin);
        if (((pin - 999) > 0) && ((9999 - pin) >= 0))
        {
            j = 0;
        }
        else
        {
            printf("\nYour entered PIN is of wrong format.\n");
            j = 1;
        }
    } while (j);

    goto services;

    // USER LOGIN

login:;

    // Collecting Data From outside FILE

    FILE *data;
    data = fopen("account.txt", "r");

    fscanf(data, "%d", &pin);
    fscanf(data, "%s", &name);
    fscanf(data, "%f", &balance);

    fclose(data);

    // User Name entering

    char uname[30];
    do
    {
        printf("Login to your Virtual Wallet\n\n");
        printf("User Name : ");
        scanf("%s", &uname);
        if (strcmp(name, uname) != 0)
        {
            printf("Your entered User Name does not exist \n");
        }
    } while (strcmp(name, uname) != 0);

    // PIN Entering

    int ipin;

    do
    {
        printf("\nEnter your 4 digit PIN : ");
        scanf("%d", &ipin);
        if (ipin != pin)
        {
            printf("\nYour entered PIN is not correct");
        }
    } while (ipin != pin);

    // Wallet Services

services:;

    printf("Welcome to our Wallet services\n\n");
    printf("1. Wallet Balance \n");
    printf("2. Withdraw Money \n");
    printf("3. Deposit Money \n");
    printf("4. Pin Change \n");
    printf("5. Name Change \n");
    printf("6. Exit \n\n");
    printf("Please proceed with your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Balance Check

        printf("\nYour current account balance is : %.2f\n", balance);
        break;

    case 2:
        // Cash Withdrawl

        printf("Enter the ammount to be withdrawn from your account : ");
        float wd;
        scanf("%f", &wd);
        if (wd > 0)
        {
            if (wd <= balance)
            {
                balance -= wd;
                printf("\nYour new account balance is : %.2f\n", balance);
            }
            else
            {
                printf("\nYou have insufficient balance for this withdrawl\n");
            }
        }
        else
        {
            printf("\nYou have entered an incorrect value\n");
        }
        break;

    case 3:
        // Cash Deposit

        printf("Enter the ammount to be deposited to your account : ");
        float dp;
        scanf("%f", &dp);
        if (dp > 0)
        {
            balance += dp;
            printf("\nYour new account balance is : %.2f\n", balance);
        }
        else
        {
            printf("You have entered an incorrect value.\n");
        }
        break;

    case 4:
        // PIN Change

        printf("Please enter your new PIN : ");
        scanf("%d", &pin);
        printf("\nYour new PIN is : %d\n", pin);
        break;

    case 5:
        // User Name change

        printf("Please enter your new User Name : ");
        scanf("%s", &name);
        printf("\nYour new User Name is : %s\n", name);
        break;

    case 6:
        // Exit

        printf("Thank you for choosing our wallet \n");
        goto exiting;
        break;
    default:
        printf("Your entered choice is Not-Applicable\n");
        goto services;
        break;
    }

// EXIT Statements
exiting:;

    char answer = 0;

    printf("\nDo you want to use any other services (Y/N) : ");
    scanf(" %c", &answer);

    switch (answer)
    {
    case 'y':
    case 'Y':
        goto services;
        break;

    case 'n':
    case 'N':
        printf("\nTHANK YOU FOR USING OUR SERVICES.\n");
        printf("\nPress ENTER key to exit.\n");

        remove("account.txt");

        FILE *data;
        data = fopen("account.txt", "a");

        fprintf(data, "%d ", pin);
        fprintf(data, "%s ", name);
        fprintf(data, "%f ", balance);

        fclose(data);

        break;
    default:
        printf("\nYou did not respond correctly...\n");
        goto exiting;
        break;
    }

    char ch;
    scanf("%c", &ch);
    getchar();

    return 0;
}
