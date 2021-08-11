#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "../dijkstra.h"

// quantidade de leitores lendo
int readcount = 0;

//
// TODO: Definição dos semáforos (variaveis precisam ser globais)
//

// dado compartilhado que os leitores e escritores acessarão
int shared = 0;

// prototipos das funcoes
void * leitor(void *);
void * escritor(void *);
int gera_rand(int);

int main(int argc, char ** argv)
{
    // threads dos leitores
    pthread_t * tl;

    // threads dos escritores
    pthread_t * te;

    int i;

    srand(time(NULL));

    if ( argc < 3 )
    {
        printf("Usage: %s num_leitores num_escritores\n", argv[0]);
        return 0;
    }

    //
    // TODO: Criação dos semáforos (aqui é quando define seus
    // valores, usando a biblioteca dijkstra.h
    // 
 
    // num leitores
    int N_LEITORES = atoi(argv[1]);
    
    // num escritores
    int N_ESCRITORES = atoi(argv[2]);
    
    // gerando uma lista de threads de leitores
    tl = malloc(N_LEITORES * sizeof(pthread_t));

    // iniciando as threads dos leitores
    for (i = 0; i < N_LEITORES; i++)
    {
        pthread_create(&tl[i], NULL, leitor, (void *)i);
    }
    
    // gerando uma lista de threads de leitores
    te = malloc(N_ESCRITORES * sizeof(pthread_t));

    // iniciando as threads dos escritores
    for (i = 0; i < N_ESCRITORES; i++)
    {
        pthread_create(&te[i], NULL, escritor, (void *)i);
    }

    // aguardando as threads leitoras terminarem
    for (i = 0; i < N_LEITORES; i++)
    {
        pthread_join(tl[i], NULL);
    }
    
    // aguardando as threads escritoras terminarem
    for (i = 0; i < N_ESCRITORES; i++)
    {
        pthread_join(te[i], NULL);
    }

    //
    // TODO: Excluindo os semaforos (dijkstra.h)
    // 

    // liberando a memoria alocada
    free(tl);
    free(te);

    return 0;
}

void * leitor(void * id)
{
    usleep(gera_rand(1000000));

    // convertendo o Id do leitor para int
    int i = (int)id;

    //
    // TODO: precisa fazer o controle de acesso à entrada do leitor
    //
    
    printf("> Leitor %d tentando acesso\n",i);

        // leitor acessando o valor de shared
        printf("\t> Leitor %d acessando shared: %d - readcount: %d\n",
                i,shared,readcount);

    //
    // TODO: precisa fazer a saída do leitor e liberação do acesso
    //

    printf("< Leitor %d liberando acesso\n",i);

}

void * escritor(void * id)
{
    usleep(gera_rand(1000000));
    
    // convertendo o Id do leitor para int
    int i = (int)id;

    //
    // TODO: precisa controlar o acesso do escritor ao recurso
    //
    
    printf("+ Escritor %d tentando acesso\n",i);
    
    printf("\t+ Escritor %d conseguiu acesso\n",i);
    int rnd = gera_rand(100);
    printf("\t+ Escritor %d gravando o valor %d em shared\n", i, rnd);
    usleep(gera_rand(1000000));
    shared = rnd;
    
    //
    // TODO: precisa fazer a saída do escritor e liberação do acesso
    //
    
    printf("+ Escritor %d saindo\n",i);
}

int gera_rand(int limit)
{
    // 0 a (limit -1)
    return rand()%limit;
}

