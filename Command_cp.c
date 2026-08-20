#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//  ./cpx      <source.txt>  <dest.txt>
//  argv[0]    argv[1]       argv[2]


/*
open source file for reading
open or create destination file
read data from source 
write  it into destination
close both files
*/

#define MAX_BUFFER_SIZE 1024

int main(int argc ,char **argv)
{ 
    if(argc != 3)
    {
        printf("Error : Insufficient Arguments\n");
        printf("usage : %s <source_filename> <destination_filename>\n",argv[0]);
        return -1;
    }

    int fdSrc = 0,fdDest = 0,iRet = 0;
    char Buffer[MAX_BUFFER_SIZE];

    memset(Buffer,'\0',sizeof(Buffer));

    fdSrc = open(argv[1],O_RDONLY);

    if(fdSrc == -1)
    {
        printf("Error : Unble to open source file : %s\n",argv[1]);
        return -1;
    }

    fdDest = creat(argv[2],0777);
    
    if(fdDest == -1)
    {
        printf("Error : Unble to create destination file : %s\n",argv[2]);
        close(fdSrc);
        return -1;
    }

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer))) > 0)
    {
        write(fdDest,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));
    }

    printf("Success : copy activity done\n");

    close(fdSrc);
    close(fdDest);
    return 0;
}