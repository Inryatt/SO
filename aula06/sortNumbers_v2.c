#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/
#define LINEMAXSIZE 150

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return (x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int i = 0, numSize = 0;
    int *numbers;
    FILE *fp = NULL;
    char line[LINEMAXSIZE];

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    char tmp[10];
    while (fscanf(fp, "%s", tmp) == 1)
    {

        numSize++;
    }
      //  printf("Numsize = %d\n",numSize);

    numbers = (int *)malloc(sizeof(int) * numSize);

    rewind(fp);
    int l = 0;
    while (fscanf(fp, "%d", numbers+l) == 1)
    {
        l++;
    }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for (i = 0; i < numSize; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}