#include "libreriaTP2.h"
#include<stdio.h>
#include<windows.h>

void presentacion()
{
    system("cls");
    for(int i=0; i<5; i++)
    {
        printf("* * * * * * * * * * * * * * * *\n");
        printf("*                             *\n");
        printf("*      Trabajo Practico 2     *\n");
        printf("*         Estructuras         *\n");
        printf("*                             *\n");
        printf("* * * * * * * * * * * * * * * *\n");
        Sleep(1000);
        system("cls");
        printf("                               \n");
        printf("                               \n");
        printf("       Trabajo Practico 2      \n");
        printf("          Estructuras          \n");
        printf("                               \n");
        printf("                               \n");
        Sleep(1000);
        system("cls");
    }
    printf("* * * * * * * * * * * * * * * *\n");
    printf("*                             *\n");
    printf("*      Trabajo Practico 2     *\n");
    printf("*         Estructuras         *\n");
    printf("*                             *\n");
    printf("* * * * * * * * * * * * * * * *\n");
    Sleep(100);
    system("cls");
    printf("* *   *   * *     * *   * * * *\n");
    printf("*   *   *     * *     *      *\n");
    printf("*      Trabajo Practico 2     *\n");
    printf("*         Estructuras         *\n");
    printf("*                             *\n");
    printf("* * * * * * * * * * * * * * * *\n");
    Sleep(100);
    system("cls");
    printf("*     *   * *     * *         *\n");
    printf("* *     *     * *       * * * *\n");
    printf("*   *    abajo Practic*       *\n");
    printf("*      Tr Estr  tur s o 2     *\n");
    printf("*             uc   a          *\n");
    printf("* *           * *     * * * * *\n");
    Sleep(100);
    system("cls");
    printf("                               \n");
    printf("        *     * *       *     *\n");
    printf("*   *    aba P  tic*      *    \n");
    printf("* *      tr  trac so           \n");
    printf("*       Tr  Esur jo      a    *\n");
    printf("* *           * uc* 2       * *\n");
    Sleep(100);
    system("cls");
    printf("                               \n");
    printf("                               \n");
    printf("        *     * *       *     *\n");
    printf("*   *    aba P  tic*      *    \n");
    printf("* *      tr  trac so           \n");
    printf("*       Tr  Esur jo      a    *\n");
    Sleep(100);
    system("cls");
    printf("                               \n");
    printf("                               \n");
    printf("                               \n");
    printf("        *     * *       *     *\n");
    printf("*   *    aba P  tic*      *    \n");
    printf("* *      tr  trac so           \n");
    Sleep(100);
    system("cls");
    printf("                               \n");
    printf("                               \n");
    printf("                               \n");
    printf("                               \n");
    printf("        *     * *       *     *\n");
    printf("*   *    aba P  tic*      *    \n");
    Sleep(100);
    system("cls");
    printf("                               \n");
    printf("                               \n");
    printf("                               \n");
    printf("                               \n");
    printf("                               \n");
    printf("        *     * *       *     *\n");
    Sleep(100);
    system("cls");
}

void menu()
{
    printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                                               *\n");
    printf("* Ingrese:                                      *\n");
    printf("* 1. Agregar persona                            *\n");
    printf("* 2. Eliminar persona                           *\n");
    printf("* 3. Ordenar lista de personas alfabeticamente  *\n");
    printf("* 4. Imprimir Grafico de Edades                 *\n");
    printf("* 5. Salir del programa                         *\n");
    printf("*                                               *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

int ingresarEntero(char* mensaje)
{
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

char ingresarChar(char* mensaje)
{
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

void ingresarString(char mensaje[], char aux[])
{
    printf("%s",mensaje);
    gets(aux);
}

long int ingresarDocumento(char* mensaje)
{
    long int aux;
    printf("%s",mensaje);
    scanf("%ld",&aux);
    return aux;
}