#include <pthread.h>
#include <stdio.h>

pthread_t tid0, tid1;

long conta = 0;

void * t0()
{
    long i;
    for (i = 0; i < 1000000; i++)
    {
        conta = conta + 5;
    }

    printf("Encerrei t0\n");
}

void * t1()
{
    long i;
    for (i = 0; i < 1000000; i++)
    {
        conta = conta + 2;
    }

    printf("Encerrei t1 \n");
}

int main (int argc, char ** argv)
{
    pthread_create(&tid0, NULL, t0, NULL);
    pthread_create(&tid1, NULL, t1, NULL);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    printf("O valor de conta eh: %d\n", conta);

    return 0;
}
