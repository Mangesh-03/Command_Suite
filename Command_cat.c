#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

/*
    Accept filename from commandLine
    check whether file is existing
    if it is display data on console
    if it is not exists display no such file or directory 
*/
#define MAX_BUFFER_SIZE 1024

int main(int argc ,char **argv)
{ 
    if(argc != 2)
    {
        printf("Error : Insufficient Arguments\n");
        printf("usage : %s <filename> \n",argv[0]);
        return -1;
    }

    if(access(argv[1],F_OK) != 0)
    {
        printf("cat: %s: No such file or directory\n",argv[1]);
        return 0;
    }
    
    int fd = 0;

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("Error : Unble to open file\n");
        return -1;
    }

    char Buffer[MAX_BUFFER_SIZE];
    int iRet = 0;

    memset(Buffer,'\0',sizeof(Buffer));

    while((iRet = read(fd,Buffer,sizeof(Buffer))) > 0)
    {
        write(1,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));
    }

    printf("\n");
    
    close(fd);

    return 0;
}