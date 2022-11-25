#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct login // before the first use of `l`.
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

void login(void);
void registration(void);

int main(void)
{
    int option;

    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d", &option);

    getchar(); // catching newline.

    if (option == 1)
    {
        system("CLS");
        registration();
    }

    else if (option == 2)
    {
        system("CLS");
        login();
    }
}

void login(void)
{
    char username[30], password[20];
    FILE *log;

    log = fopen("login.txt", "r");
    if (log == NULL)
    {
        fputs("Error at opening File!", log);
        exit(1);
    }

    struct login l;

    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username:  ");
    scanf("%s", username);
    // fgets(username, 30, stdin);
    printf("\nPassword: \n ");
    scanf("%s", password);
    // fgets(password, 20, stdin);

    while (fread(&l, sizeof(l), 0, log))
    {
        rewind(log);
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
        {
            printf("\nSuccessful Login\n");
        }
        else
        {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
        }
        }
    rewind(log);

    fclose(log);
    printf("******************************************* ");
    printf("error ");
    printf("***************************************** ");
}

void registration(void)
{
    char firstname[15];
    FILE *log;

    log = fopen("login.txt", "a+");
    if (log == NULL)
    {
        fputs("Error at opening File!", log);
        exit(1);
    }

    struct login l;

    printf("\n We need to enter some details for registration.\n\n");
    printf("\nEnter First Name:\n");
    scanf("%s", l.fname);
    printf("Enter last name:\n");
    scanf("%s", l.lname);

    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");

    printf("\nEnter Username:\n");
    scanf("%s", l.username);
    printf("\nEnter Password:\n");
    scanf("%s", l.password);

    fprintf(log, " %s  %s  %s  %s \n", l.fname, l.lname, l.username, l.password);
    // fprintf(&l, sizeof(l), 1, log);
    fclose(log);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n", firstname);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
    getchar();
    system("CLS");
    login();
}
