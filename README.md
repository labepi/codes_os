# codes_os

Exemplos de códigos sobre conceitos de Sistemas Operacionais.

Os códigos aqui são baseados nos exemplos do livro Sistemas
Distribuídos, Uirá Ribeiro, 2005.

## Intruções de Compilação e Execução

Para a compilação de um arquivo exemplo *codigo.c*:

```bash
gcc codigo.c -o codigo
```

Para códigos que utilizem threads:

```bash
gcc -pthread codigo.c -o codigo
```

Para executar o código gerado:

```bash
./codigo
```

