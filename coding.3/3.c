#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("I am child (pid:%d)\nhello\n", (int)getpid());
    }
    else
    {
        sleep(2);
        printf("I am parent of %d (pid:%d)\ngoodbye\n",
               rc, (int)getpid());
    }
    return 0;
}

