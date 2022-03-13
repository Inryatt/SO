#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 150 /* or other suitable maximum line size */

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line[LINEMAXSIZE];

    /* Validate number of arguments */
    /*https://idp.ua.pt/idp/profile/SAML2/Redirec */
    if (argc < 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    for (int k = 0; k < argc - 1; k++)
    {
        /* Open the file provided as argument */
        errno = 0;
        fp = fopen(argv[k+1], "r");
        if (fp == NULL)
        {
            perror("Error opening file!");
            return EXIT_FAILURE;
        }

        /* Read all the lines of the file */
        int i = 0;
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            printf("%d -> %s", i, line); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
            i++;
        }

        fclose(fp);
        printf("\n======================================================================\n\n");
    }
    return EXIT_SUCCESS;
}
