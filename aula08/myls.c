#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int arg, char *argv[]){

    printf("=====================================================\n");
    int ret;
    if((ret=fork())<0){
        printf("Erro na criação do processo filho;\n");
        return EXIT_FAILURE;
    }
    if (ret==0){
        if(execl("/bin/ls","/bin/ls","-la",NULL)<0){
            perror("ERRO no execl.\n");
            return EXIT_FAILURE;
        };
    }
    else
    {
        waitpid(ret);
        printf("=====================================================\n");
    }
    
    return EXIT_SUCCESS;
}