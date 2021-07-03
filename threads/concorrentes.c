#include <pthread.h>
#include <stdio.h>

void * ProcessoLeve1()
{
    int i;
    printf("T1\n");
    for (i = 1; i < 100000; i++)
    //for (i = 1; i < 100; i++)
        printf("\tThread 1 - %d\n",i);
}

void * ProcessoLeve2()
{
    int i;
    printf("T2\n");
    for (i = 100000; i < 200000; i++)
    //for (i = 100; i < 200; i++)
        printf("\t\tThread 2 - %d\n",i);
}

int main()
{
    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, ProcessoLeve1, NULL);
    pthread_create(&thread2, NULL, ProcessoLeve2, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    pthread_detach(thread1);
    pthread_detach(thread2);

    return 0;
}

