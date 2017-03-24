#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    Imprime k digitos de um numero n
*/
//função que calcula o digito i
void digito(int,int,int*);

int main(void)
{
    int i,n,k, nfinal;

    printf("Escolha um número e o seu k-ésimo digito\n");
    scanf("%d %d",&n,&k);

    //loop que repete o processo para todos os digitos do 1º até o k-ésimo
    for(i=1; i<=k; i++)
    {//aplica-se a função utilizando os dados adquiridos
    digito(n,i,&nfinal);
    printf("O %dº digito é %d\n",i,nfinal);
    }
    //apresentação do resultado


    return EXIT_SUCCESS;
}

void digito(int _n, int _i, int* _nfinal)
{
    int DIV,nsemi,_k1;
    // pretende-se dividir o numero[n] inteiro por 10^(k-1)[DIV]
    // o digito de menor peso do numero obtido será o pretendido
    _k1=_i-1;
    DIV=pow(10,_k1);
    nsemi=(_n/DIV);
    //como o resultado é um inteiro e queremos o numero menor deste inteiro
    //calcula-se o resto da divisão por 10
    *_nfinal=(nsemi%10);

    return;
}
