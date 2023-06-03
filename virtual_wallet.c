#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct customer
{
    char name[50];
    int pin;
    char phone_no[11];
    float balance;
} cust_list[100],admin;

int current_user, end_user;

void copy_data()
{
    int i;

    FILE *fptr;
    fptr = fopen("account.dat", "r");

    fseek(fptr, 0, 2);
    int end = ftell(fptr);
    fseek(fptr, 0, 0);

    for (i = 0; ftell(fptr) != end; i++)
    {
        fscanf(fptr, "%d %s %s %f", &cust_list[i].pin, cust_list[i].name, cust_list[i].phone_no, &cust_list[i].balance);
    }

    fclose(fptr);

    end_user = i;

    //

    fptr = fopen("admin.dat", "r");

    fscanf(fptr, "%d %s", &admin.pin, admin.name);

    fclose(fptr);
}

void startup()
{
    system("clear");

    printf("\n***********************************************");
    printf("\n*         WELCOME TO YOUR VIRTUAL WALLET      *");
    printf("\n***********************************************\n\n");

    printf("\nPlease Choose an option below.\n");
    printf("\n1. Log In\n");
    printf("\n2. New User Account\n");
    printf("\n3. Admin Login\n");
    printf("\n: ");

    int select;
    scanf("%d", &select);

    switch (select)
    {
    case 1:
        login();
        break;
    case 2:
        acc_creation();
        break;
    case 3:
        admin_login();
        break;
    }
}

void login()
{
    float ibalance = 0;
    int ipin;
    char iname[50];
    char iphone_no[11];

    while (1)
    {
        // User Name entering

        char uname[50];
        do
        {
            int flag = 1;

            printf("Login to your Virtual Wallet\n\n");
            printf("User Name : ");
            scanf("%s", &uname);

            for (int i = 0; i <= end_user; i++)
            {
                if (strcmp(cust_list[i].name, uname) == 0)
                {
                    current_user = i;
                    flag = 0;
                    break;
                }
            }

            if (flag)
                printf("\nThe User does not exist.\n");
            else
                break;
        } while (1);

        // PIN Entering

        int upin;

        do
        {
            printf("\nEnter your 4 digit PIN : ");
            scanf("%d", &upin);

            printf("\n");

            if (cust_list[current_user].pin != upin)
            {
                printf("\nYour entered PIN is not correct");
            }
        } while (cust_list[current_user].pin != upin);
        break;
    }

    services();
}

void acc_creation()
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

    current_user = end_user++;

    cust_list[current_user].pin = ipin;
    cust_list[current_user].balance = ibalance;
    strcpy(cust_list[current_user].name, iname);
    strcpy(cust_list[current_user].phone_no, iphone_no);

    services();
}

void admin_login()
{
    while (1)
    {
        // User Name entering

        char uname[50];
        do
        {
            int flag = 1;

            printf("Login as ADMIN\n\n");
            printf("User Name : ");
            scanf("%s", &uname);

            for (int i = 0; i <= end_user; i++)
            {
                if (strcmp(admin.name, uname) == 0)
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                printf("\nWrong Admin Account\n");
            else
                break;
        } while (1);

        // PIN Entering

        int upin;

        do
        {
            printf("\nEnter your 4 digit PIN : ");
            scanf("%d", &upin);

            printf("\n");

            if (admin.pin != upin)
            {
                printf("\nYour entered PIN is not correct");
            }
        } while (admin.pin != upin);
        break;
    }

    for (int i = 0; i < end_user; i++)
    {
        if(i == 0)
        {
            printf("Si No. \t\t User Name \t\t PIN \t\t Phone No. \t\t Balance\n\n");
        }
        else
        {
        printf("%d \t\t %s \t\t %d \t\t %s \t\t %.2f\n\n", i, cust_list[i-1].name, cust_list[i-1].pin, cust_list[i-1].phone_no, cust_list[i-1].balance);
        }
    }

    char ch;
    scanf("%c", &ch);
    getchar();

    exit(1);
}

void services()
{
    system("clear");

start:;

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

        statement();
        break;

    case 2:
        // Cash Withdrawl

        withdraw();
        break;

    case 3:
        // Cash Deposit

        deposit();
        break;

    case 4:
        // PIN Change

        pin_ch();
        break;

    case 5:
        // User Name change

        name_ch();
        break;

    case 6:
        // Phone Number change

        phone_no_ch();
        break;

    case 7:
        // Exit

        exiting();
        break;

    default:
        printf("Your entered choice is Not-Applicable\n");
        goto start;
        break;
    }
}

void statement()
{
    printf("\n********** Account Statement ************\n");
    printf("\nUser Name : %s\n", cust_list[current_user].name);
    printf("\nPhone Number : %s\n", cust_list[current_user].phone_no);
    printf("\nWallet Balance : %.2f\n", cust_list[current_user].balance);
    printf("\n");

    char ch;
    scanf("%c", &ch);
    getchar();

    services();
}

void deposit()
{
    printf("Enter the ammount to be deposited to your account : ");
    float dp;
    scanf("%f", &dp);

    if (dp > 0)
    {
        cust_list[current_user].balance += dp;
        printf("\nYour new account balance is : %.2f\n", cust_list[current_user].balance);
    }
    else
    {
        printf("You have entered an incorrect value.\n");
    }

    char ch;
    scanf("%c", &ch);
    getchar();

    services();
}

void withdraw()
{
    printf("Enter the ammount to be withdrawn from your account : ");
    float wd;
    scanf("%f", &wd);

    // printf("\nEnter the number to be transferred to : \n");
    // int temp;
    // scanf("%d", &temp);

    if (wd > 0)
    {
        if (wd <= cust_list[current_user].balance)
        {
            cust_list[current_user].balance -= wd;
            printf("\nYour new account balance is : %.2f\n", cust_list[current_user].balance);
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

    char ch;
    scanf("%c", &ch);
    getchar();

    services();
}

void pin_ch()
{
    int ipin, j;

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

    cust_list[current_user].pin = ipin;

    char ch;
    scanf("%c", &ch);
    getchar();

    services();
}

void name_ch()
{
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

    strcpy(cust_list[current_user].name, iname);

    char ch;
    scanf("%c", &ch);
    getchar();

    services();
}

void phone_no_ch()
{
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

    strcpy(cust_list[current_user].phone_no, iphone_no);

    char ch;
    scanf("%c", &ch);
    getchar();

    services();
}

void update_user()
{
    FILE *data;
    data = fopen("account.dat", "w");

    for (int i = 0; i < end_user; i++)
    {
        fprintf(data, "%d %s %s %f\n", cust_list[i].pin, cust_list[i].name, cust_list[i].phone_no, cust_list[i].balance);
    }

    fclose(data);
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

        services();
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

    update_user();

    char ch;
    scanf("%c", &ch);
    getchar();
    exit(1);
}

int main()
{
    copy_data();

    startup();

    return 0;
}

// ****************************************************************************************************************//
