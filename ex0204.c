#include <stdio.h>
#include <stdlib.h>
/*
    Adivinha o número aleatório gerado entre 1 e n, em m tentativas
*/
//funções que geram o número máximo gerado e o número máximo de tentativas
int escolheN(int);
int escolheM(int);
//gerador do número inteiro a adivinhar
int GeradorK(int,int*);
//função que imprime e lê o texto de cada jogada
int tentativa(int,int*);
//função que compara o valor introduzido com o valor gerado
int comparador(int,int,int,int*);

int main(void)
{
    int n,k,x,comp,m,jogada, result;
    //escolha do valor máximo gerado [n]
    n=escolheN(n);
    //escolha do valor máximo de tentativas [m]
    m=escolheM(m);
    //escolher o valor aleatório [k] entre 1 e n
    GeradorK(n,&k);

    //criação do loop das várias jogadas até ao fim do jogo
    //a jogado começa na 1ª, aumentando 1 por loop
    //o loop termina quando o nº de jogadas é maior que m ou comp=1
    for(jogada=1; jogada<=m && comp!=1; jogada++)
    {
        tentativa(n,&x);
        comparador(x,k,n,&comp);
    }
    //quando o loop termina ocorre um incremento da jogada
    //isto resulta num valor final de jogadas errado que é corrigido de seguida
    jogada--;
    //na situação em que o loop termina porque comp=1 isto deve-se ao jogador ter acertado
    if (comp==1)
        printf("Ganhou em %d tentativas", jogada);
    else
    //na outra situação o loop termina porque ultrapassou o numero max de tentativas m
        printf("Perdeu! Esgotou todas as tentativas.");

    return EXIT_SUCCESS;
}

int comparador(int _x, int _k, int _n, int* _comp)
{//comparação do numero introduzido [_x] e o gerado [_k]
 //é atribuido o valor 0 a *_comp nas situações em que o numero nao esta correto
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
        //ao atribuir o valor 1 a *_comp quando correto o loop irá terminar
            *_comp=1;
        }
    else
        {
            printf("O número inserido não se encontra na gama de valores válidos.\n");
            *_comp=0;
        }
    return;
}
int tentativa(int _n, int* _x)
{   //texto gerado em todas as jogadas e leitura do numero introduzido
    printf("Escolha um número entre 1 e %d\n", _n);
    scanf("%d", &*_x);
    return;
}
int GeradorK(int _n,int* _k)
{   //gera um numero aleatorio
    srandom(time(NULL));
    //random()%_n - restringe esse mesmo valor a [0,(n-1)]
    //ao somar um o intervalo passa a ser [1,n]
    *_k=random()%_n+1;
    return;
}
int escolheN(int _n)
{   //atribuição do valor máximo à variavel _n que devolve para n na main
    _n=50000;
    return _n;
}
int escolheM(int _m)
{   //atribuição do valor max de tentativas a _m que devolve para m
    _m=15;
    //informação do numero maximo de tentativas
    printf("Tem %d tentativas.\n", _m);
    return _m;
}
