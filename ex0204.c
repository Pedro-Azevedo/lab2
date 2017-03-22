#include <stdio.h>
#include <stdlib.h>

int escolheN(int);
int escolheM(int);
void GeradorK(int,int*);
void tentativa(int,int*);
void comparador(int,int,int,int*);

int main(void)
{
    int n,k,x,comp,m,jogada, result;

    n=escolheN(n);
    m=escolheM(m);
    GeradorK(n,&k);

    for(jogada=1; jogada<=m && comp!=1; jogada++)
    {
        tentativa(n,&x);
        comparador(x,k,n,&comp);
    }

    jogada--;

    if (comp==1)
        printf("Ganhou em %d tentativas", jogada);
    else
        printf("Perdeu! Esgotou todas as tentativas.");

    return EXIT_SUCCESS;
}

void comparador(int _x, int _k, int _n, int* _comp)
{
    if(_x>_k && _x<=_n)
        {
            printf("O número é menor que %d\n", _x);
            *_comp=0;
        }
    else if (_x<_k && _x>=1)
        {
            printf("O número é maior que %d\n", _x);
            *_comp=0;
        }
    else if (_x==_k)
        {
            *_comp=1;
        }
    else
        {
            printf("O número inserido não se encontra na gama de valores válidos.\n");
            *_comp=9;
        }
    return;
}
void tentativa(int _n, int* _x)
{
    printf("Escolha um número entre 1 e %d\n", _n);
    scanf("%d", &*_x);
    return;
}
void GeradorK(int _n,int* _k)
{
    int n1;
    n1=_n-1;
    srandom(time(NULL));
    *_k=random()%n1+1;
    return;
}
int escolheN(int _n)
{
    _n=50000;
    return _n;
}
int escolheM(int _m)
{
    _m=15;
    printf("Tem %d tentativas.\n", _m);
    return _m;
}
