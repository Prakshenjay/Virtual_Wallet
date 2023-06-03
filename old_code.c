#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct customer
{
    char name[50];
    int pin;
    char phone_no[11];
    float balance;
};
void startup();

void login(int *pin, char *name, float *balance);

void acc_creation(int *pin, char *name, float *balance, char *phone_no);

void statement(float *balance, char *name, char *phone_no);

void deposit(float *balance);

void withdraw(float *balance);

void pin_ch(int *pin);

void name_ch(char *name);

void phone_no_ch(char *phone_no);

int exiting();

void saving_user(int *pin, char *name, float *balance, char *phone_no);

int main()
{
    // INTRODUCTION

    printf("\n***********************************************");
    printf("\n*         WELCOME TO YOUR VIRTUAL WALLET      *");
    printf("\n***********************************************\n\n");

    printf("\nPlease Choose an option below.\n");
    printf("\n1. Log In\n");
    printf("\n2. New User Account\n");
    printf("\n: ");

    int select;
    scanf("%d", &select);

    int pin;
    char name[50];
    char phone_no[11];
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
    fscanf(data, "%s", &phone_no);
    fscanf(data, "%f", &balance);

    fclose(data);

    // User Name entering

    char user[50];
    do
    {
        int flag1 = 0;
        int flag2 = 0;

        printf("Login to your Virtual Wallet\n\n");
        printf("User Name or Phone No. : ");
        scanf("%s", &user);

        if (strcmp(name, user) != 0)
        {
            flag1 = 1;
        }

        if (strcmp(phone_no, user) != 0)
        {
            flag2 = 1;
        }

        if (flag1 && flag2)
            printf("\nThe User does not exist.\n");
        else
            break;
    } while (1);

    // PIN Entering

    int ipin;

    do
    {
        printf("\nEnter your 4 digit PIN : ");
        scanf("%d", &ipin);

        printf("\n");

        if (ipin != pin)
        {
            printf("\nYour entered PIN is not correct");
        }
    } while (ipin != pin);

    // Wallet Services

services:;

    printf("Welcome to our Wallet services\n");
    printf("\n");
    printf("1. Wallet Statement \n");
    printf("2. Withdraw Money \n");
    printf("3. Deposit Money \n");
    printf("4. Pin Change \n");
    printf("5. Name Change \n");
    printf("6. Phone Number Change\n");
    printf("7. Exit \n");
    printf("\n");
    printf("Please proceed with your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Account Statement

        statement(&balance, name, phone_no);
        break;

    case 2:
        // Cash Withdrawl

        withdraw(&balance);
        break;

    case 3:
        // Cash Deposit

        deposit(&balance);
        break;

    case 4:
        // PIN Change

        pin_ch(&pin);
        break;

    case 5:
        // User Name change

        name_ch(name);
        break;

    case 6:
        // Phone Number change

        phone_no_ch(phone_no);
        break;

    case 7:
        // Exit

        exiting(&pin, &balance, name, phone_no);
        break;

    default:
        printf("Your entered choice is Not-Applicable\n");
        goto services;
        break;
    }

    if (exiting())
    {
        goto services;
    }

    saving_user(&pin, name, &balance, phone_no);

    char ch;
    scanf("%c", &ch);
    getchar();
    
//EXIT Statements
        
exiting:;

    printf("Thank you for choosing our wallet \n");

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

// ****************************************************************************************************************//

void reading_user(int *pin, char *name, float *balance)
{
}

void login(int *pin, char *name, float *balance)
{
}

void creation(int *pin, char *name, float *balance, char *phone_no)
{
    float ibalance = 0;
    int ipin;
    char iname[50];
    char iphone_no[11];

    int i, j, k;
    do
    {
        printf("\nEnter your User name : ");
        scanf("%s", &iname);
        if (1)
        {
            i = 0;
        }
        else
        {
            printf("\nYour entered USER NAME is of the wrong format.\n");
            i = 1;
        }
    } while (i);

    do
    {
        printf("\nEnter a new 4 digit PIN : ");
        scanf("%d", &ipin);
        if (((ipin - 999) > 0) && ((9999 - ipin) >= 0))
        {
            j = 0;
        }
        else
        {
            printf("\nYour entered PIN is of the wrong format.\n");
            j = 1;
        }
    } while (j);

    do
    {
        printf("\nEnter your Phone No. : ");
        scanf("%s", &iphone_no);
        if (1)
        {
            k = 0;
        }
        else
        {
            printf("\nYour entered Phone Number is of the wrong format.\n");
            k = 1;
        }
    } while (k);

    *pin = ipin;
    *balance = ibalance;
    strcpy(name, iname);
    strcpy(phone_no, iphone_no);
}

void statement(float *balance, char *name, char *phone_no)
{
    printf("\n********** Account Statement ************\n");
    printf("\nUser Name : %s\n", name);
    printf("\nPhone Number : %10d\n", phone_no);
    printf("\nWallet Balance : %.2f\n", *balance);
    printf("\n");
}

void deposit(float *balance)
{
    printf("Enter the ammount to be deposited to your account : ");
    float dp;
    scanf("%f", &dp);

    if (dp > 0)
    {
        *balance += dp;
        printf("\nYour new account balance is : %.2f\n", *balance);
    }
    else
    {
        printf("You have entered an incorrect value.\n");
    }
}

void withdraw(float *balance)
{
    printf("Enter the ammount to be withdrawn from your account : ");
    float wd;
    scanf("%f", &wd);

    // printf("\nEnter the number to be transferred to : \n");
    // int temp;
    // scanf("%d", &temp);

    if (wd > 0)
    {
        if (wd <= *balance)
        {
            *balance -= wd;
            printf("\nYour new account balance is : %.2f\n", *balance);
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
}

void pin_ch(int *pin)
{
    printf("Please enter your new PIN : ");

    int ipin,j;

    do
    {
        printf("\nEnter a new 4 digit PIN : ");
        scanf("%d", &ipin);
        if (((ipin - 999) > 0) && ((9999 - ipin) >= 0))
        {
            j = 0;
        }
        else
        {
            printf("\nYour entered PIN is of the wrong format.\n");
            j = 1;
        }
    } while (j);

    printf("\n");
    printf("\nYour new PIN is : %d\n", ipin);

    *pin = ipin;
}

void name_ch(char *name)
{
    printf("Please enter your new User Name : ");

    int i;
    char iname[50];

    do
    {
        printf("\nEnter your User name : ");
        scanf("%s", &iname);
        if (1)
        {
            i = 0;
        }
        else
        {
            printf("\nYour entered USER NAME is of the wrong format.\n");
            i = 1;
        }
    } while (i);

    printf("\nYour new User Name is : %s\n", iname);

    strcpy(name, iname);
}

void phone_no_ch(char *phone_no)
{
    printf("Please enter your new Phone Number : ");

    int k;
    char iphone_no[11];

    do
    {
        printf("\nEnter your Phone No. : ");
        scanf("%s", &iphone_no);
        if (1)
        {
            k = 0;
        }
        else
        {
            printf("\nYour entered Phone Number is of the wrong format.\n");
            k = 1;
        }
    } while (k);

    printf("\nYour new Phone No. is : %s\n", iphone_no);

    strcpy(phone_no, iphone_no);
}

int exiting()
{
start:

    printf("Thank you for choosing our wallet \n");

    char answer = 0;

    printf("\nDo you want to use any other services (Y/N) : ");
    scanf("%c", &answer);

    switch (answer)
    {
    case 'y':
    case 'Y':

        return 1;
        break;

    case 'n':
    case 'N':
        printf("\nTHANK YOU FOR USING OUR SERVICES.\n");
        printf("\nPress ENTER key to exit.\n");

        break;

    default:
        printf("\nYou did not respond correctly...\n");
        goto start;
        break;
    }

    char ch;
    scanf("%c", &ch);
    getchar();
}

void saving_user(int *pin, char *name, float *balance, char *phone_no)
{
    remove("account.txt");

    FILE *data;
    data = fopen("account.txt", "a");

    fprintf(data, "%d ", *pin);
    fprintf(data, "%s ", name);
    fprintf(data, "%s ", phone_no);
    fprintf(data, "%f ", *balance);

    fclose(data);
}