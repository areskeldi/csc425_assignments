#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <sys/wait.h>
 
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
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("ls");         // program: "ls"
        myargs[1] = strdup("-a");         // argument: -a
        myargs[2] = NULL;                 // marks end of array
        char *const envp[2] = {"", NULL}; // here you can set environment variables.
 
        execvp(myargs[0], myargs);
        execle("/usr/bin/ls", "-a", NULL, envp);
 
        printf("this shouldn't print out");
    }
    else
    {
        // parent goes down this path (main)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
               rc, wc, (int)getpid());
    }
    return 0;
}
