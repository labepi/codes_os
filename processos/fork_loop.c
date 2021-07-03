#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int pid;

    printf("Meu numero de processo é %d. Vou criar um processo filho.\n", getpid());

    pid = fork();

    if (pid == 0)
    {
        printf("\t\tProcesso filho criado com PID %d\n",getpid());
        printf("\t\tVou ficar executando indefinidamente\n");
        for(;;);
    }
    else
    {
        sleep(5);
        printf("O processo pai termina e deixa filho orfao\n");
        printf("Veja se o processo filho continua rodando com o comando ps\n");
    }

    exit(0);
}
