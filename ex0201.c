#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Função para verificar se um número é primo
int eprimo(int);

int main()
{
    int n=0;
    // Ciclo para imprimir os primos casados entre 2 e 1000
    for(n=2; n<1000; n++)
    {
        //Condição de primos casados
        if(eprimo(n)==1 && eprimo(n+2)==1) 
            printf("%d e %d são primos casados\n", n, n+2);
    }

    return EXIT_SUCCESS;
}


int eprimo(int _n)
{
    // isNotPrime é a flag que deteta se um número não é primo
    int isNotPrime=0, num=0, max=0;
    // para verificar que o número é primo basta fazer o ciclo entre 2 e a raiz do número
    max=(int)sqrt(_n);
    for (num=2; num<=max; num++)
    {
        // Se for divisivel por algum número entre 2 e a raiz então não é primo
        if (_n%num==0)
            isNotPrime=1;
    }

    // se não for primo retorna 0, se for primo retorna 1
    if (isNotPrime==1)
        return 0;
    else
        return 1;
}
