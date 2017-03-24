#include <stdio.h>
#include <stdlib.h>

//Função de verificação do número
int verification(long int);

int main(void)
{
    long int num=0L;
    int test=0, ver=0;

    printf("Please enter a number:\n");

    test=scanf("%ld", &num);

    // Testar o retorno do scanf
    if(test!=1 || num<0)
    {
        printf("Error: That is not a valid number\n");
        exit(EXIT_FAILURE);
    }

    ver=verification(num);

    // Verificar o retorno da função 
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
    // O resto da divisão de um número por 10 dá o último dígito desse número
    digit=_n%10;
    // Dividir um número de k digitos por 10 e guardá-lo como inteiro guarda os k-1 dígitos mais significativos do número
    num=_n/10;
    //Condição de Validade -> põe a flag a 1 e retorna-a; 
    if((num%7)==digit)
        isValid=1;
    return isValid;
}
