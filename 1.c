#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char *argv[])
{
    int var = 100;
    printf("hello world (pid:%d)\n", (int)getpid());
    printf("var before fork: %d\n", var);
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        printf("var from child: %d\n", var);
        printf("Changing var in child to 200\n");
        var = 200;
        printf("The changed var from child after the previous change: %d\n", var);
    }
    else
    {
        printf("hello, I am parent of %d (pid:%d)\n",
               rc, (int)getpid());
        printf("var after fork: %d\n", var);
        printf("Changing var in parent to 300\n");
        var = 300;
        printf("The changed var from parent after the previous change: %d\n", var);
    }
    return 0;
}

