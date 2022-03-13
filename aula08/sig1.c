#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned int i;

    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= 10) { 
        printf("\r%08u ", i++);
        fflush(stdout);         //dá flush no buffer do printf
        sleep(1);               //para debug com prints usar fprintf(stderr)
    }
    printf("\n");

    return EXIT_SUCCESS;
}
