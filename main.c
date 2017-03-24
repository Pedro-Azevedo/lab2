#include <stdio.h>
#include <stdlib.h>
char digito(int, int);
int numberofdigits(int);

int main(void)
{
    int num=0, teste=0, kdigits=0, k=0;
    char ch='\0';
    printf("Insira um número inteiro positivo:\n");
    teste=scanf("%d", &num);
    if (teste!=1 || num<=0)
    {
        printf("Erro: o número inserido não é válido\n");
        exit(EXIT_FAILURE);
    }

    kdigits = numberofdigits(num);


    for(k=0; k<kdigits; k++)
    {
        ch= digito(num, k);
        printf("O digito %d do número é %c\n", k, ch);
    }

    return EXIT_SUCCESS;
}


int numberofdigits(int _n)
{
    int count=0;
    while (_n!=0)
    {
        _n/=10;
        count++;
    }

    return count;
}


char digito(int _number, int _kdigit)
{
    int flag=0, digit=0;
    char ch='\0';
    for (flag=0; flag<=_kdigit; flag++)
    {
        digit=_number%10;
        _number/=10;
    }

    ch= digit + '0';
    return ch;
}
