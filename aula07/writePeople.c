#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct
{
    int age;
    float height;
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
    int howMany;
    printf("Quantas pessoas são para guardar?\n");
    scanf("%d",&howMany);
	printf("gotcha é pa guardar %d pessoas\n",howMany);    
 	int age;
	float height;
	//char name[64];
  	//scanf("%*c"); 
    for(i = 0 ; i < howMany ; i++)
    {    
	printf("Nome?\n");
	scanf(" %/scanf("%*c");
	printf("Idade?\n");
        scanf(" %d",&p.age);
	

	printf("Altura?\n");
	
	scanf(" %f",&p.height);
	
        //p.height = height;

        fwrite(&p, sizeof(Person), 1, fp);
	//printf("Current: %d Target: %d",i,howMany);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
