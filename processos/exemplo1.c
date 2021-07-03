#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main()
{
    // OBS: insira aqui o PID do processo filho que ficou em looping com
    // o código fork_loop.c
    int pid = 11111111;

    printf("Sou o processo %d ",getpid());
    printf("e matarei o processo %d\n",pid);

    // SIGKILL = 9 (termina o processo incondicionalmente)
    kill(pid,9);

    return 0;
}

