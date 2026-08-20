#include<stdio.h>
#include<unistd.h>
#include<sys/utsname.h>


// ./rmx     path
//  argv[0]   argv[1]
//  argc = 2

/*
    call the system call unlink 
    decrement the link count of file 
*/

int main(int argc ,char **argv)
{ 
    if(argc != 2)
    {
        printf("Error : Insufficient Arguments\n");
        printf("usage : %s <path> \n",argv[0]);
        return -1;
    }
    
    if(access(argv[1],F_OK) != 0)
    {
        printf("Error : No such file \n");
        return 0;
    }

    if(unlink(argv[1]) == -1)
    {
        printf("Error : unble to remove file\n");
        return -1;
    }

    return 0;
}