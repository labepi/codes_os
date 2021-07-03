#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Vou chamar o programa cat para ler o conteudo de /etc/issue\n");

    system("/bin/cat /etc/issue");
    
    printf("Esta mensagem sera impressa\n");

    return(0);
}

