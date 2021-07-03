#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    //char *cmd[] = {"cat", "/etc/passwd", (char *)0};
    char *cmd[] = {"cat", "/etc/issue", (char *)0};
    
    printf("Vou chamar o programa cat para ler o conteudo de /etc/issue\n");

    execv("/bin/cat", cmd);

    printf("Esta mensagem nao sera impressa.\n");

    exit(0);
}
