#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

void* funcao_thread(void* arg)
{
    printf("\tNova thread criada com PID %d e TID %d\n", 
            getpid(), gettid());
    sleep(50);
    printf("Thread com o ID %d finalizada.\n", gettid());
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    printf("Processo pesado PID %d\n", getpid());
    
    pthread_create(&thread1, NULL, &funcao_thread, NULL);
    
    pthread_create(&thread2, NULL, &funcao_thread, NULL);

    //printf("Identificador da thread %lu\n",thread1);
    //printf("Identificador da thread %lu\n",thread2);
    
    sleep(20);

    printf("Main esperando as threads finalizarem\n");

    // aguardando as threads finalizarem
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main finalizando\n");


    return 0;
}

