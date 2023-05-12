# Descrição

Neste diretório estão os códigos base (esqueletos) para a resolução dos
problemas clássicos de sincronização de processos.

A implementação dos problemas deve utilizar a biblioteca de semáforos POSIX (Portable Operating System Interface), disponível em sistemas Linux.

# Arquivos e Diretórios

```
./buffer/           -   Problema do buffer limitado (bounded buffer) com produtor-consumidor
./leitores/         -   Problema dos leitores e escritores
./filosofos/        -   Problema do jantar dos filósofos
```

# Compilação

Para compilar os códigos:

```bash
gcc -pthread codigo.c -o codigo
```

Para executar o código gerado:

```bash
./codigo
```

Cada código pede um número diferente de parâmetros, observe o modo de
uso informado após sua execução.

# Implementação com semáforos POSIX

Para um exemplo de como utilizar semáforos POSIX no Linux, ver o seguinte
arquivo:

```
/codes_os/sincronizacao/exclusaomutua_sem.c
```

Este código resolve o problema de condição de corrida da variável
compartilhada conta e está todo comentado.

