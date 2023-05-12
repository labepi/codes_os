#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

//
// TODO: Definição dos semáforos (variaveis precisam ser globais)
//

// lista quem esta de posse de um chopstick
int *chopstick_use;

// numero de filosofos
int N_FILOS;

// prototipos das funcoes
void * filosofo(void *);
void pegar(int, int);
void liberar(int, int);
int gera_rand(int);

int main(int argc, char ** argv)
{
    // threads dos filosofos
    pthread_t * tids;

    long i;

    srand(time(NULL));

    if ( argc < 2 )
    {
        printf("Usage: %s num_filosofos\n", argv[0]);
        return 0;
    }
    
    // numero de filosofos
    N_FILOS = atoi(argv[1]);
    
    // gerando uma lista de threads de filosofos
    tids = malloc(N_FILOS * sizeof(pthread_t));

    // gerando uma lista de uso dos chopsticks
    chopstick_use = malloc(N_FILOS * sizeof(int));
    
    // um chopstick esta livre se estiver -1
    for (i = 0; i < N_FILOS; i++)
    {
        chopstick_use[i] = -1;
    }

    //
    // TODO: Criação dos semáforos (aqui é quando define seus
    // valores)
    // 
 
    // iniciando as threads dos filosofos
    for (i = 0; i < N_FILOS; i++)
    {
        pthread_create(&tids[i], NULL, filosofo, (void *)i);
    }
    
    // aguardando as threads dos filosofos terminarem
    for (i = 0; i < N_FILOS; i++)
    {
        pthread_join(tids[i], NULL);
    }
    
    //
    // TODO: Excluindo os semaforos
    // 

    // liberando a memoria alocada
    free(tids);

    return 0;
}

void * filosofo(void * id)
{
    // convertendo o Id do filosofo para int
    long i = (long)id;
    
    printf("\t> Filosofo %d pensando\n",i);
    usleep(gera_rand(1000000));

    // ordem dos chopsticks depende do id  
    int c1, c2;

    // OBS: alterando a ordem de pegar o chopstick para evitar deadlock
    if (i%2 == 0) // com base no id do filosofo (par ou impar)
    {
        c1 = i;             // esquerda
        c2 = (i+1)%N_FILOS; // direita
    }
    else
    {
        c1 = (i+1)%N_FILOS; // direita
        c2 = i;             // esquerda 
    }


    //
    // TODO: precisa garantir que mais de um filosofo nao pegue o mesmo
    // chopstick simultaneamente
    //
    pegar(i, c1);
    pegar(i, c2);
    
    printf("\t> Filosofo %d comendo\n",i);
    usleep(gera_rand(1000000));
    
    //
    // TODO: precisa garantir que os filosofos liberem os chopsticks
    // após usar
    //
    liberar(i, c1);
    liberar(i, c2);

}

// filosofo 'i' quer pegar o chopstick definido por 'num'
void pegar(int i, int num)
{
    if (chopstick_use[num] != -1)
    {
        printf("===== ALERTA DO FILOSOFO %d =====\n===== CHOPSTICK[%d] EM USO POR %d =====\n",
                i,num,chopstick_use[num]);
    }
    chopstick_use[num] = i;
    printf("+ Filosofo %d pegou o chopstick[%d]\n",i,num);
}

// filosofo 'i' quer liberar o chopstick definido por 'num'
void liberar(int i, int num)
{
    chopstick_use[num] = -1;
    printf("- Filosofo %d liberou o chopstick[%d]\n",i,num);
}

int gera_rand(int limit)
{
    // 0 a (limit -1)
    return rand()%limit;
}

