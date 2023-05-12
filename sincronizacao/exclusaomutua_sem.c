#include <pthread.h>
#include <stdio.h>
// adicionando a biblioteca POSIX para semáforos
#include <semaphore.h>

pthread_t tid0, tid1;

long conta = 0;

// criando um semáforo global
sem_t mutex;

void * t0()
{
    long i;
    for (i = 0; i < 1000000; i++)
    {
        // entrada da seção crítica
        // wait
        sem_wait(&mutex);

        // seção crítica
        conta = conta + 5;

        // saída da seção crítica
        // signal
        sem_post(&mutex);
    }

    printf("Encerrei t0\n");
}

void * t1()
{
    long i;
    for (i = 0; i < 1000000; i++)
    {
        sem_wait(&mutex);

        conta = conta + 2;

        sem_post(&mutex);
    }

    printf("Encerrei t1 \n");
}

int main (int argc, char ** argv)
{
    // iniciando o semáforo com 'mutex' com valor '1'
    // o '0' indica que ele é compartilhado entre as threads
    sem_init(&mutex, 0, 1);

    pthread_create(&tid0, NULL, t0, NULL);
    pthread_create(&tid1, NULL, t1, NULL);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    printf("O valor de conta eh: %ld\n", conta);

    // finalizando o semáforo
    sem_destroy(&mutex);

    return 0;
}
