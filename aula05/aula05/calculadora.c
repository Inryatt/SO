#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int main(int argc, char **argv)
{
    int i;
    double res,arg1,arg2;
    arg1=atof(argv[1]);
    arg2=atof(argv[3]);

    bool toPrint=1;
    if(argc==4)
    {	    
    	if(*argv[2]=='+'){
		res=arg1+arg2;
	}
		else if(*argv[2]=='-'){
			res=arg1-arg2;
	    		}
			else if(*argv[2]=='x'|| *argv[2]=='*'){
				res=arg1*arg2;
				}
				else if(*argv[2]=='/'){
					res=arg1/arg2;
				}
					else if(*argv[2]=='p'){
						res=pow(arg1, arg2);
					}
						else {
							printf("something went wrong yo. \n");
							toPrint=0;
						}
	if(toPrint)
	printf("O resultado é: %f. \n",res);
    }
    else
    {
	fprintf(stderr,"Numero máximo de argumentos excedido. \n");
    	return -1;
    }
    return EXIT_SUCCESS;
}
