/*
Programa: TP2.c
Descripción: Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
flag de estado.
Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el
siguiente:
1. Agregar una persona
2. Borrar una persona
3. Imprimir lista ordenada por nombre
4. Imprimir gráfico de edades
Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
• Menores de 18
• De 19 a 35
• Mayores de 35.
En el eje Y se marcarán la cantidad de personas en el grupo, y en el eje X el grupo.
Gráfico para una estadística de 6 personas con edad menor a 18, 4 personas con edades entre
19 y 35, y 5 personas con edades mayores a 35.
Autor: Gustavo Barrajón, Damian Exequiel Segura, Martin Ponce, Cesar Nahuel Fernandez, Vittorio Tristan Mazar
Modificó:
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include "libreriaTP2.h"
#define ANSI_COLOR_RED   "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE  "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define MAX 20            // Hacer un programa que defina un array de 20 ítems de esta estructura

struct persona
{
    char nombre[40];
    long int dni;
    int edad, flag;
}listaPersonas[MAX];

struct persona cargarPersona();
void imprimirPersona(struct persona pp);
struct persona eliminarPersona();
struct persona ordenarLista();
void imprimirGrafico(struct persona pp[]);

void main()
{
    int opcion, i=0;
    char continuar;
    
    presentacion();
    for(;opcion!=5;)
    {
        menu();
        scanf("%d", &opcion);
        fflush(stdin);
        
        switch (opcion)
        {
        case 1:
            
            do
            {
                if(strcmp(listaPersonas[i].nombre, "")==0)
                {
                    listaPersonas[i]=cargarPersona();
                    i++;

                    continuar=ingresarChar("Desea continuar? (s/n) ");
                }
                
            } while ((continuar=='s' || continuar=='S') && i<MAX);
            Sleep(1000);
            system("cls");
            break;
    
        case 2:
            eliminarPersona();
            Sleep(2000);
            system("cls");
            break;

        case 3:
            ordenarLista();
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;

        case 4:
            imprimirGrafico(listaPersonas);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        
        case 5:
            system("cls");
            cierre();
            break;
        
        default:
            printf("La opcion ingresada no es correcta");
            Sleep(1000);
            system("cls");
            break;

        }

        fflush(stdin);
    } 
}

struct persona cargarPersona()
{
    struct persona pers;
    fflush(stdin);

    printf("Datos de la persona:\n");
    ingresarString ("Nombre: ", pers.nombre);
    fflush(stdin);
    pers.dni=ingresarDocumento("DNI: ");
    pers.edad=ingresarEntero("Edad: ");
    pers.flag=0;
    fflush(stdin);
    
    return pers;
}


void imprimirPersona(struct persona pp)
{
    puts("--------------------------------------------------");
    
    if(pp.flag==0)
    {
        printf("Datos de la persona:\n");
        printf("Nombre: %s\n", pp.nombre);
        printf("DNI: %ld\n", pp.dni);
        printf("Edad: %d\n", pp.edad);
    }
}


struct persona eliminarPersona()
{
    int i, bandera=0;
    char option;
    char name[25];
    printf("Ingrese el nombre de la a eliminar de la lista: ");
    gets(name);

    for(i=0; i<MAX; i++)
    {
        if(strcmp(listaPersonas[i].nombre, name)==0)
        {
            imprimirPersona(listaPersonas[i]);
            option=ingresarChar("Esta seguro de eliminarlo? (s/n) ");
            
            if(option=='s'|| option=='S')
            {
                listaPersonas[i].flag=1;
                printf(ANSI_COLOR_RED "La persona fue eliminada" ANSI_COLOR_RESET "\n");
            }
            bandera=1;
        }
    }

    if(bandera==0)
    {
        printf(ANSI_COLOR_RED "No se encontro esa persona en la lista" ANSI_COLOR_RESET "\n");
    }
    
    return listaPersonas[MAX];
}

struct persona ordenarLista()
{
    char auxNombre[40];
    long int auxDNI;
    int auxEdad;
    for(int i=0; i<MAX-1; i++)
    {
        for(int j=i+1; j<MAX; j++)
        {
            if(strcmp(listaPersonas[i].nombre, listaPersonas[j].nombre)>0)
            {
                strcpy(auxNombre, listaPersonas[i].nombre);
                strcpy(listaPersonas[i].nombre, listaPersonas[j].nombre);
                strcpy(listaPersonas[j].nombre, auxNombre);

                auxDNI= listaPersonas[i].dni;
                listaPersonas[i].dni= listaPersonas[j].dni;
                listaPersonas[j].dni= auxDNI;
                
                auxEdad= listaPersonas[i].edad;
                listaPersonas[i].edad= listaPersonas[j].edad;
                listaPersonas[j].edad= auxEdad;
            }
        }
    }

    printf(ANSI_COLOR_BLUE "Lista ordenada alfabeticamente" ANSI_COLOR_RESET "\n");
    for(int i=0; i<MAX; i++)
    {
        if(strcmp(listaPersonas[i].nombre, "") !=0)
        {
            imprimirPersona(listaPersonas[i]);
        }
    }
    return listaPersonas[MAX];
}

void imprimirGrafico(struct persona pp[])
{
    
    int i, j, mayor = 0, filas;
    int contadores[3];
    
    printf("\n----------------------\n" ANSI_COLOR_GREEN  "  GRAFICO DE EDADES" ANSI_COLOR_RESET "\n----------------------\n");
    // Inicializo contadores en 0
    for (i = 0; i < 3; i++) {
        contadores[i] = 0;
    }
    // Recorro el array de personas y cuento cantidad de cada grupo de edades
    for (i = 0; i < MAX; i++) {
        if (pp[i].edad > 0 && pp[i].edad < 19 && pp[i].flag == 0 && pp[i].nombre!="") 
        {
            contadores[0]++;
        }
        else {
            if (pp[i].edad > 18 && pp[i].edad < 36 && pp[i].flag == 0 && pp[i].nombre!="") 
            {
                contadores[1]++;
            }
            if (pp[i].edad > 35 && pp[i].flag == 0 && pp[i].nombre!="" ) 
            {
                contadores[2]++;
            }
        } 
    } 
    // Encuentro el grupo de edades con mas personas registradas
    if (contadores[0] >= contadores[1] && contadores[0] >= contadores[2]) 
    {
        mayor = contadores[0];
    }
    else 
    {
        if (contadores[1] >= contadores[0] && contadores[1] >= contadores[2])
        {
            mayor = contadores[1];
        }
        if (contadores[2] >= contadores[0] && contadores[2] >= contadores[1])
        {
            mayor = contadores[2];
        }
    }
    filas = mayor; // Declaro la cantidad de filas en base al contador mayor
    //Imprimo el grafico
    for (i = 0; i < mayor; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            if (contadores[j] >= filas) 
            {
                printf("*\t");
                
            }
            else 
            {
                printf(" \t");
            } 
        } 
        filas--;
        printf("\n");
    } 
    printf(ANSI_COLOR_GREEN "<18   19-35    >35" ANSI_COLOR_RESET "\n\n");
}