# Descrição

Neste diretório estão os códigos base (esqueletos) para a resolução dos
problemas clássicos de sincronização de processos.

A implementação dos problemas utiliza semáforos a partir das funções
definidas pelo livro de Sistemas Distribuídos, Uirá Ribeiro.

# Arquivos e Diretórios

```
./dijkstra.h        -   Arquivo principal que define os semáforos
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

Cada código pede um número diferente de parametros, observe o modo de
uso informado após sua execução.

