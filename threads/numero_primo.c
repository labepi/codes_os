#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void * procuranumeroprimo(void *arg)
{
    int numeroprimo = 2;
    int totalnumeros = *((int*) arg);

    printf("Calcular primos ate %d.\n\n",totalnumeros);
    printf("Sao primos: ");
    sleep(1);
    while(1)
    {
        int fatordivisao;
        int flagnumeroprimo = 1;
        for (fatordivisao = 2; fatordivisao < numeroprimo; ++fatordivisao)
        {
            if (numeroprimo % fatordivisao == 0) // se nao for primo
            {
                flagnumeroprimo = 0;
                break;
            }
        }
        if (flagnumeroprimo) // eh primo
        {
            printf(" %d ",numeroprimo);
            if (--totalnumeros == 0)
                return (void*) numeroprimo;
        }
        ++numeroprimo;
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    int total = 10;
    int primo;
    pthread_create(&thread, NULL, &procuranumeroprimo, &total);
    pthread_join(thread, (void*)&primo);
    printf("\n\nO %d numero primo é %d.\n",total,primo);

    return 0;
}

