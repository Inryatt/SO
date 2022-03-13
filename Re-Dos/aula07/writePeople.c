#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i;
    Person p = {35, 1.65, "xpto"};

    Person hotel[100];
    int numP;
    printf("Quantas pessoas a guardar?\n");
    scanf("%d",&numP);

    char tmpName[100];
    int tmpAge;
    float tmpHeight;
    for(i=0;i<numP;i++){
        printf("Pessoa %d\n",i);

        printf("Nome?\n");
        scanf("%s",tmpName);

        printf("Idade?\n");
        scanf("%d",&tmpAge);

        printf("Altura?\n");
        scanf("%f",&tmpHeight);

        hotel[i].height=tmpHeight;
        hotel[i].age=tmpAge;
        strcpy(hotel[i].name,tmpName);
    }
    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }



    /* Write 10 itens on a file */
    for(i = 0 ; i < numP ; i++)
    {    
        p=hotel[i];
        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
