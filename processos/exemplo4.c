#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int value = 5;

int main(int argc, const char *argv[])
{
    pid_t pid, pid1;

    /* gera um processo filho */
    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }
    else if (pid == 0)
    {
        pid1 = getpid();
        printf("child: pid = %d\n", pid); /* A */
        printf("child: pid1 = %d\n", pid1); /* B */
    }
    else
    {
        pid1 = getpid();
        printf("parent: pid = %d\n", pid); /* C */
        printf("parent: pid1 = %d\n", pid1); /* D */
        wait(0);
    }
    
    return 0;
}
