#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int id;
    id = fork();

    if (id != 0)
    {
        printf("Sou o pai esperando pelo filho %d\n", id);
        wait(0);
        printf("Meu filho acabou, terminando\n");
    }
    else
    {
        printf("Sou o filho %d, esperarei 10 segundos\n", getpid());
        sleep(10);
        printf("Ja esperei, terminando...\n");
    }

    return 0;
}
