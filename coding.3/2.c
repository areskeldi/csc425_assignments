#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int fd = open("1.c", O_RDONLY);
    if(fd == -1 ){
        printf("Can’t open this file");
        return 0;
    }
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        char character1;
        read(fd, &character1,1);
        printf("Printing a character from file 1,c\n%c\n", character1);
    }
    else
    {
        wait(NULL);
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
               rc, (int)getpid());
        char character1;
        read(fd, &character1,1);
        printf("Printing a character from file 1.c\n%c\n", character1);
    }
    return 0;
}
