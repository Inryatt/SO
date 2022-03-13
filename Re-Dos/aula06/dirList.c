#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/

void listDir(char dirname[],char spacing[])
{
    DIR *dp; 
    struct dirent *dent;
    char nextDir[400];
    dp = opendir(dirname);

    char newSpace[30];
    strcpy(newSpace,spacing); 
    if(dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    dent = readdir(dp);
    while(dent!=NULL) 
    {
        if(dent->d_name[0] != '.') /* do not list hidden dirs/files */
        {
            if(dent->d_type==DT_DIR){
                printf("%sd %s/%s\n",spacing,dirname,dent->d_name);
                strcpy(nextDir,dirname);
                strcat(nextDir,"/");
                strcat(nextDir,dent->d_name);
                strcat(newSpace," ");
                
                listDir(nextDir,newSpace);
            }
            else if (dent->d_type==DT_REG){
                printf("%s  %s/%s\n",spacing,dirname,dent->d_name);
            }
            else{
                printf("idkbro\n");
            }
        }

        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }
    char initialSpace[30];
    strcpy(initialSpace," ");
    listDir(argv[1],initialSpace);
    
    return EXIT_SUCCESS;
}

