#include <stdio.h>
#include <stdlib.h>

int verification(long int);

int main(void)
{
    long int num=0L;
    int test=0, ver=0;

    printf("Please enter a number:\n");

    test=scanf("%ld", &num);

    if(test!=1 || num<0)
    {
        printf("Error: That is not a valid number\n");
        exit(EXIT_FAILURE);
    }

    ver=verification(num);

    if(ver==1)
        printf("That is a valid number\n");

    else
        printf("Invalid number\n");

    return EXIT_SUCCESS;
}


int verification (long int _n)
{
    int isValid=0, digit=0;
    long int num=0;
    digit=_n%10; //guarda o último digito
    num=_n/10; // como se trata da divisºao inteira permite que se faça um shift para a 
               //direita do número para analisar o número sem o último dígito
    if((num%7)==digit) // condição do problema
        isValid=1;
    return isValid;
}
