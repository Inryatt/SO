#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	int nArgc=3;
	if ((argc-1)==nArgc)
    {	
		int i;
        double res;
        char *trash;
        printf("debuggin %s\n",argv[2]);
        printf("debuggin %d\n",*argv[2]);
        printf("x= %d\n",'+');
   
    	if(*argv[2]=='x')
        {
            printf("debuggin %s",argv[1]);
            //res=strtod(*argv[1],&trash)+strtod(*argv[3],&trash);

        }
        printf("Resultado: %f\n",res);
    	return EXIT_SUCCESS;
	}
	else {
		printf("Número de argumentos incorreto. \n");
		printf("Inseridos: %d Necessários: %d \n",(argc-1),nArgc); 
		return 1;	
	} 
}
