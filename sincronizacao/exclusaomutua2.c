#include <pthread.h>
#include <stdio.h>

pthread_t tid0, tid1;
int turn;
int shared;
int flag[2];

void * p0()
{
    int i;
    for (i = 0; i < 1000000; i++)
    {
        flag[0] = 1;
        turn = 1;
        while(flag[1] == 1 && turn == 1){}
        shared = shared + 5;
        flag[0] = 0;
    }
}

void * p1()
{
    int i;
    for (i = 0; i < 1000000; i++)
    {
        flag[1] = 1;
        turn = 0;
        while(flag[0] == 1 && turn == 0){}
        shared = shared + 2;
        flag[1] = 0;
    }
}

int main (int argc, char ** argv)
{
    flag[0] = 0;
    flag[1] = 0;

    pthread_create(&tid0, NULL, p0, NULL);
    pthread_create(&tid1, NULL, p1, NULL);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    printf("O valor de shared é: %d\n", shared);

    return 0;
}
