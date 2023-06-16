/*
1 Crie um programa que contenha um array de float contendo 10 elementos.
Utilizando aritmética de ponteiro, imprima o endereço de cada posição
desse array.
*/
#include <stdio.h>

int main() 
{
    float array[10];
    int i;
    
    // Imprimindo o endereço de cada posição do array
    printf("Enderecos do array:\n");
    
    for(i = 0; i < 10; i++) 
    {
        printf("Endereco do elemento %d: %p\n", i, &(array[i]));
    }
    
    return 0;
}

/*
2 Crie um programa que contenha uma matriz de float contendo 3 linhas e 3
colunas. Utilizando aritmética de ponteiro, imprima o endereço de cada
posição dessa matriz.
*/

#include <stdio.h>

int main() 
{
    float mat[3][3];
    int i, j;
    
    printf("Enderecos da matriz:\n");
    
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("Endereco da matriz linha %d, coluna %d: %p\n", i, i, &(mat[i]));
        }
    }
    return 0;
}

/*
3 Crie um programa que contenha um array de inteiros contendo 5 elementos.
Utilizando apenas aritmética de ponteiros, leia esse array do teclado e
imprima o dobro de cada valor lido.
*/

#include <stdio.h>

#define ARRAY 5 //tamanho do array

void dobrarValores(int *array, int tamanho);
int main() 
{
    int array[ARRAY];
    int i;

    for(i = 0; i < ARRAY; i++) 
    {
        printf("Digite o %dº elemento do array: ", i+1);
        scanf("%d", &array[i]);
    }

    dobrarValores(array, ARRAY);

    printf("Valores dobrados:\n");
    for(i = 0; i < ARRAY; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void dobrarValores(int *array, int tamanho) 
{
    int *p = array;  // Ponteiro para percorrer o array
    int i;

    for(i = 0; i < tamanho; i++) 
    {
        *p *= 2;  // Dobra o valor do elemento apontado por p
        p++;      // Move o ponteiro para o próximo elemento do array
    }
}

/*
4 Crie um programa que contenha um array contendo 5 elementos inteiros.
Leia esse array do teclado e imprima o endereço das posições contendo
valores pares.
*/

#include <stdio.h>

int main() 
{
    int array[5];
    int i;

    for(i = 0; i < 5; i++) 
    {
        printf("Digite o %dº numero inteiro: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Enderecos das posicoes com valores pares:\n");

    for(i = 0; i < 5; i++) 
    {
        if(array[i] % 2 == 0) 
        {
            printf("Posicao %d: %p\n", i, &array[i]);
        }
    }

    return 0;
}

/*
5 Elabore um programa que receba duas strings digitadas pelo usuário e
verifique se a segunda string ocorre dentro da primeira. Use aritmética de
ponteiros para acessar os caracteres das strings.
*/

#include <stdio.h>
#include <stdlib.h>

int stringOcorrencia(const char *str1, const char *str2);
int main() 
{
    char str1[100], str2[100];

    printf("Digite a primeira string: ");
    fgets(str1, 100, stdin);

    printf("Digite a segunda string: ");
    fgets(str2, 100, stdin);

    if(stringOcorrencia(str1, str2))
    {
        printf("A segunda string ocorre dentro da primeira.\n");
    }
    else
    {
        printf("A segunda string não ocorre dentro da primeira.\n");
    }

    return 0;
}

int stringOcorrencia(const char *str1, const char *str2) 
{
    const char *p1, *p2, *p3;

    while(*str1) 
    {
        p1 = str1;
        p2 = str2;

        while(*p1 && *p2 && (*p1 == *p2)) 
        {
            p1++;
            p2++;
        }

        if(!*p2)
        {
            return 1;
        }
        str1++;
    }

    return 0;
}

/*
6 Elabore um programa que dado um array e um valor do mesmo tipo do
array, preencha os elementos de array com esse valor. Não utilize índices
para percorrer o array, apenas aritmética de ponteiros.
*/

#include <stdio.h>

void preencherArray(int *array, int tamanho, int valor);
int main() 
{
    int tamanho = 5;
    int array[tamanho];
    int valor = 42;
    int i;

    preencherArray(array, tamanho, valor);

    printf("Array preenchido:\n");
    
    for(i = 0; i < tamanho; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void preencherArray(int *array, int tamanho, int valor) 
{
    int *p = array;

    while(p < (array + tamanho)) 
    {
        *p = valor;
        p++;
    }
}

/*
7 Escreva um programa que receba um array de inteiros com 10 elementos
digitados pelo usuário e encontre o menor (min) e o maior (max) elemento
desse array. Utilize ponteiros tanto para acessar o array quanto para acessar
as variáveis min e max, ou seja, são necessários pelo menos 3 ponteiros.
*/

#include <stdio.h>

void AcharMinMax(int *array, int size, int *min, int *max);
int main() 
{
    int array[10];
    int i;
    int min, max;
    int *ptrArray;
    int *ptrMin;
    int *ptrMax;
    
    for(i = 0; i < 10; i++) 
    {
        printf("Digite o %dº numero inteiro: ", i+1);
        scanf("%d", &array[i]);
    }
    
    ptrArray = array;
    ptrMin = &min;
    ptrMax = &max;
    
    AcharMinMax(ptrArray, 10, ptrMin, ptrMax);
    
    printf("O menor elemento eh: %d\n", *ptrMin);
    printf("O maior elemento eh: %d\n", *ptrMax);
    
    return 0;
}

void AcharMinMax(int *array, int size, int *min, int *max) 
{
    *min = *max = array[0];
    int i;
    
    for(i = 1; i < size; i++) 
    {
        if(array[i] < *min) 
        {
            *min = array[i];
        }
        
        if (array[i] > *max) 
        {
            *max = array[i];
        }
    }
}


/*
8 Considere a seguinte declaração: int A, *B, **C, ***D; Escreva um
programa que leia a variável ‘A’ e calcule e exiba o dobro, o triplo e o
quádruplo desse valor utilizando apenas os ponteiros B, C e D. O ponteiro B
deve ser usada para calcular o dobro, C o triplo e D o quádruplo.
*/

#include <stdio.h>

int main() 
{
    int A, *B, **C, ***D;
    
    //Ponteiros apontando para as respectivas variáveis
    B = &A;
    C = &B;
    D = &C;
    
    //Leitura do valor de A
    printf("Digite um valor para A: ");
    scanf("%d", &A);
    
    //Calcula e exibi o dobro, triplo e quádruplo de A
    printf("O dobro de A eh: %d\n", 2 * *B);
    printf("O triplo de A eh: %d\n", 3 * **C);
    printf("O quadruplo de A eh: %d\n", 4 * ***D);
    
    return 0;
}