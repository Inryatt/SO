#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char **argv){
	if(argc!=3){
		printf("Numero de argumentos inválido. Por favor inclua 2 argumentos. \n");
		return 1;
	}
	else{
		srand(time(NULL));
		int target=rand()%(atoi((argv[1])+1)+atoi(argv[2]));
		int c=0;
		//DEBUG		printf("target is  %d",target);
		int guess;
		while(guess!=target){
			c++;
			printf("Type your guess!\n");
			scanf("%d",&guess);
			printf("\n");
			if(guess==target){
				printf("GG you win!\n Number of attempts: %d \n",c);
			}
			else if(guess>target){
				printf("Too high!\n");
			}
				else printf("Too low!\n");
		}
		return 0;
	}



}
