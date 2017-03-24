#include <stdio.h>
#include <stdlib.h>

// função que retorna o digito do número
char digito(int, int);
// função que retorna o número de dígitos do número
int numberofdigits(int);

int main(void)
{
    int num=0, teste=0, kdigits=0, k=0;
    char ch='\0';
    printf("Insira um número inteiro positivo:\n");
    teste=scanf("%d", &num);
    // Testar o número inserido
    if (teste!=1 || num<=0)
    {
        printf("Erro: o número inserido não é válido\n");
        exit(EXIT_FAILURE);
    }

    // Determinar o número de dígitos do número
    kdigits = numberofdigits(num);


    // Ciclo para imprimir todos os digitos do número
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
    // Enquanto o número não for zero vai-se dividindo por 10. O número de divisões por 10 dá o número de dígitos
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
    // Enquanto houver dígitos a funçao vai retirar o dígito (resto da divisão por 10); Depois divide o número por 10 
    // para ir percorrendo os dígitos (a divisão por 10 guarda os k-1 dígitos mais significativos
    for (flag=0; flag<=_kdigit; flag++)
    {
        digit=_number%10;
        _number/=10;
    }

    // Conversão do dígito para caracter
    ch= digit + '0';
    return ch;
}
