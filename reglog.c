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

int login( const gchar * name, const gchar * pass)
{
    
    FILE *log;

    log = fopen("login.txt", "r");
    if (log == NULL)
    {
        fputs("Error at opening File!", log);
        exit(1);
    }

    char line[255];

    while (fgets(line,sizeof(line),log))
    {
        char * token =strtok(line," ");
        char *person[4];
        int i =0;
        while (token != NULL)
        {
            person[i++] =token;
            token= strtok(NULL," ");
        }
        if (strcmp(name,  person[2]) == 0 && strcmp(pass, person[3]) == 0)
         {
            fclose(log);
            return 1;
         }
    }

  fclose(log);
  return 0;
}
int registration(const gchar * name,const gchar * lastname,const gchar * username ,const gchar * password)
{
    char firstname[15];
    FILE *log;

    log = fopen("login.txt", "a+");
    if (log == NULL) {
        return 0;
    }
    
    fprintf(log, "%s  %s  %s  %s\n", name, lastname, username, password);
    fclose(log);
    return 1;
    
}
