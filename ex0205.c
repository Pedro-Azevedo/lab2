#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição de constantes para testar o problema
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
    srandom(time(NULL)); // semente para gerar número aleatório
    int generated=0, decision=0, test=0, c=0, computerGuess=0;

    generated = rand()%(_n+1); // gera números de 0 a n

    printf("Bem-vindo ao jogo \"Adivinha o número\" \n");
    printf("Um número entre 0 e %d foi gerado e o computador tentará adivinhá-lo:\n", _n);
    printf("Ajude o computador: se a mensagem apresentada pelo computador indicar:\n");
    printf("Que o número gerado é maior: prima 1\n");
    printf("Que o número gerado é menor: prima -1\n");
    printf("Que o número gerado é igual: prima 0\n");

    while (*_mytry<=TRYING)
    {
        computerGuess=(0+_n)/2; // o computador aposta no valor médio do intervalo em que o número está contido

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
            while((c=getchar())!='\n'&& c!=EOF); // para o caso de se inserir uma letra, limpa o buffer do teclado
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
