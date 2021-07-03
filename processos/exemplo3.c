#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int value = 5;

int main(int argc, const char *argv[])
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
    {
        value += 15;
        return 0;
    }
    else
    {
        wait(0);
        printf("PARENT: value = %d\n", value); /* LINHA A */
        return 0;
    }

}
