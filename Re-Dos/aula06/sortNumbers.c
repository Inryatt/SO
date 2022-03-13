#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/
#define LINEMAXSIZE 240

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int i=0;
    int numSize=0;
    int *numbers;
   
    FILE *fp = NULL;
    char line[LINEMAXSIZE];

    if ( argc<2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    
    errno=0;

    fp=fopen(argv[1],"a");
    if (fp== NULL){
        perror("Error opening file;");
        return EXIT_FAILURE;
    }

    while( fgets(line, sizeof(line),fp)!=NULL)
    {
        numSize++;
    }
    rewind(fp);
    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * numSize);

  
    //reset the pointer on the file to go back to start
    
  /* Storing the arguments in the "array" numbers */
    while( fgets(line, sizeof(line),fp)!=NULL)
    {
        numbers[i] = atoi(line);
        i++;
    }
    fclose(fp);
    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
