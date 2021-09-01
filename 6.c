#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> 
int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    pid_t rc = fork();
    int status;

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        sleep(1);
    }
    else
    {
        // parent goes down this path (main)

        pid_t wc = waitpid(rc, &status, 0);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
               rc, wc, (int)getpid());
    }
    return 0;
}
