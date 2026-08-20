#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

// ./pwdx   DirectoryPath
//  argv[0]  argv[1]
//  argc = 1

/*
    Accept new directory path
    call chdir with that path
    call getcwd for check the changed path
*/

int main(int argc ,char **argv)
{ 
    if(argc != 2)
    {
        printf("Error : Insufficient Arguments\n");
        printf("usage : %s <directory_path> \n",argv[0]);
        return -1;
    }
    
    if(chdir(argv[1]) != -1)
    {
        printf("Error : unble to change current directory\n");
        return -1;
    }

    char Buffer[256]={'\0'};

    getcwd(Buffer,sizeof(Buffer) - 1);

    printf("Current directory change to : %s\n",Buffer);

    return 0;
}