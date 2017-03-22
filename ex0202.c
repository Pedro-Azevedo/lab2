#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    Escolhe o digito k de um numero n
*/
//função que calcula o digito k
void digito(int,int,int*);

int main(void)
{
    int n,k, nfinal;
    int test=0;

    printf("Escolha um número e o seu k-ésimo digito\n");
    test=scanf("%d %d",&n,&k);
    if(test!=1)
    {
        printf("Erro: Por favor introduza números válidos\n");
        exit(EXIT_FAILURE); 
    }
    //aplica-se a função utilizando os dados adquiridos
    digito(n,k,&nfinal);
    //apresentação do resultado
    printf("O %dº digito de %d é %d",k,n,nfinal);

    return EXIT_SUCCESS;
}

void digito(int _n, int _k, int* _nfinal)
{
    int DIV,nsemi,_k1;
    // pretende-se dividir o numero[n] inteiro por 10^(k-1)[DIV]
    // o digito de menor peso do numero obtido será o pretendido
    _k1=_k-1;
    DIV=pow(10,_k1);
    nsemi=(_n/DIV);
    //como o resultado é um inteiro e queremos o numero menor deste inteiro
    //calcula-se o resto da divisão por 10
    *_nfinal=(nsemi%10);

    return;
}
