#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    int i, numChars;
    char *username;
    char bigstring[500];
    username = getenv("NEWUSER");
    if(username != NULL)
    {
        printf("This program is being executed by %s\n", username);
    }
    else
    {
        printf("ERROR: USER not defined\n");
        return EXIT_FAILURE;
    }

    numChars = 0;
    strcpy(bigstring,"");
    for(i = 1 ; i < argc ; i++)
    {
	if(isalpha(argv[i][0])){
        numChars += strlen(argv[i]);
	

	strcat(bigstring ,argv[i]);
	strcat(bigstring," ");
	printf("DEBUG: %c\n",argv[i][0]);
	}

    }
	
    

    printf("All arguments have %d characters\n", numChars);
    printf("Today's horoscope is: %s\n",bigstring);

    return EXIT_SUCCESS;
}
