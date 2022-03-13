#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

int main(int argc, char *argv[])
{
    char text[1024];
    FILE *fp = NULL;

    time_t date;
  
    fp=fopen("command.log","a");
    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */

        if(strcmp(text, "end")) {
            printf("\n * Command to be executed: %s\n", text);
            printf("---------------------------------\n");
            system(text);

            date=time(NULL);
            char *date_str = ctime(&date);
            fprintf(fp,"%s %s\n",date_str,text );
            printf("---------------------------------\n");
        }
    } while(strcmp(text, "end"));
    fclose(fp);
    printf("-----------The End---------------\n");

    return EXIT_SUCCESS;
}
