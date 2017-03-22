#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRYING 10

void adivinhaonumero (int, int, int*);

int main(void)
{
    int mytry=1;

    adivinhaonumero(MAX, TRYING, &mytry);

    if (mytry<= TRYING)
        printf("Parabéns! Acertou no número em apenas %d tentativas\n", mytry);
    else
        printf("Infelizmente não conseguiu acertar no número no número de tentativas definido\n");

    printf("Fim do jogo\n");

    return EXIT_SUCCESS;
}

void adivinhaonumero (int _n, int _m, int* _mytry)
{
    srandom(time(NULL));
    int generated=0, decision=0, test=0, c=0, computerGuess=0;

    generated = rand()%(_n+1);

    printf("Bem-vindo ao jogo \"Adivinha o número\" \n");
    printf("Um número entre 0 e %d foi gerado e o computador tentará adivinhá-lo:\n", _n);
    printf("Ajude o computador: se a mensagem apresentada pelo computador indicar:\n");
    printf("Que o número gerado é maior: prima 1\n");
    printf("Que o número gerado é menor: prima -1\n");
    printf("Que o número gerado é igual: prima 0\n");

    while (*_mytry<=TRYING)
    {
        computerGuess=(0+_n)/2;

        if(computerGuess==generated)
            printf("O número é igual ao gerado: %d\n", computerGuess);

        else if(computerGuess > generated)
            printf("O número gerado é menor do que %d\n", computerGuess);

        else if(computerGuess < generated)
            printf("O número gerado é maior do que: %d\n", computerGuess);


        test=scanf(" %d", &decision);
        if(test!=1 || decision<-1 || decision>1)
        {
            printf ("Erro: Por favor insira um número válido no intervalo definido\n");
            while((c=getchar())!='\n'&& c!=EOF);
        }
        switch(decision)
        {
            case -1: _n=_n-2; break;
            case 0: break;
            case 1: _n=_n+2;break;
        }

        if (decision==0 && test==1)
            break;

        (*_mytry)++;
    }

}
