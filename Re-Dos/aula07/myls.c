#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

void listDir(char dirname[],char spacing[], int option,char extent[])
{
    DIR *dp; 
    struct dirent *dent;
    char nextDir[400];
    dp = opendir(dirname);

    char tmp_str[100];
    char *ext;


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

            if((dent->d_type==DT_DIR) && ( option == 1 ) ){
                printf("%sd %s/%s\n",spacing,dirname,dent->d_name);
                strcpy(nextDir,dirname);
                strcat(nextDir,"/");
                strcat(nextDir,dent->d_name);
                strcat(newSpace," ");
                
                listDir(nextDir,newSpace,option,extent);
            }
            else if ( (dent->d_type==DT_REG) && ( (option==0) || (option==2) ) )
            {
               
                if( option==2){ 
                    strcpy(tmp_str,dent->d_name);
                    ext=strchr(tmp_str,'.');
                    
                    if(ext!=NULL){
                        if (!  strcmp(ext,extent) )
                        {
                            printf("DEBUG: %s",ext);
                            printf("%s  %s/%s\n",spacing,dirname,dent->d_name);
                   
                        }
                    }

                
                }
               
                
            }
            else{
                ;
            }
        }

        dent = readdir(dp);
    }
}


int main(int argc,char* argv[]){

    int filter=-1;
    int opt;
    char ext[100];

    if (argc<2)
    {
        printf("Too little arguments! Usage: %s <fde>\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    while((opt = getopt(argc,argv,"fde:"))!=-1){

        switch(opt)
        {
            case 'f':
                filter=0;
                break;

            case 'd':

                filter=1;
                break;

            case 'e':
                filter=2; //tmp
                strcpy(ext,optarg);
                break;
            default:
                printf("Invalid option.\n");
                exit(EXIT_FAILURE);


        }
    }


     if (optind >= argc)
    {
        fprintf(stderr, "Expected argument after options\n");
        return EXIT_FAILURE;
    }

    
    char initialSpace[30];
    strcpy(initialSpace," ");
    listDir(argv[argc-1],initialSpace,filter,ext);
    
    return EXIT_SUCCESS;

}