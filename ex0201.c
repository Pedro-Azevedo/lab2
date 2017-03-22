#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eprimo(int);

int main()
{
    int n=0;
    // ciclo para imprimir os primos casados menores do que 1000
    for(n=2; n<1000; n++)
    {
        if(eprimo(n)==1 && eprimo(n+2)==1)
            printf("%d e %d são primos casados\n", n, n+2);
    }

    return EXIT_SUCCESS;
}


int eprimo(int _n)
{
    int isNotPrime=0, num=0, max=0;
    max=(int)sqrt(_n); // para testar que o número é ou nao primo basta verificar se é divisível até à raiz do número
    for (num=2; num<=max; num++)
    {
        if (_n%num==0)
            isNotPrime=1; // se não for primo ativa a a flag isNotPrime
    }
    
    // Retornos da função

    if (isNotPrime==1)
        return 0;
    else
        return 1;
}
