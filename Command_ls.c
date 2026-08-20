#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

//  .lsx      
//  argv[0]    


/*
    open the current directory (".")
    read all entry from that directory
    print the name of files
    close the directory
*/

#define MAX_BUFFER_SIZE 1024

int main(int argc ,char **argv)
{ 
    char *path = ".";

    DIR *dp = NULL;

    dp = opendir(path);

    if(dp == NULL)
    {
        printf("Error : Unble to open directory\n");
        return -1;
    }

    struct dirent *dobj ;

    while((dobj = readdir(dp)) != NULL)
    {
        printf("%s \t",dobj->d_name);
    }

    printf("\n");
    closedir(dp);

    return 0;
}