#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	int nArgc=2;
	if ((argc-1)==nArgc)
    {	
		int i;

    	for(i = 0 ; i < argc ; i++)
    	{
    	    printf("Argument %02d: \"%s\"\n", i, argv[i]);        
 	  	}
	
    	return EXIT_SUCCESS;
	}
	else {
		printf("Número de argumentos incorreto. \n");
		printf("Inseridos: %d Necessários: %d \n",(argc-1),nArgc); 
		return 1;	
	} 
}
