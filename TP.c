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
#include<string.h>
#include<stdlib.h>

struct persona
{
    char nombre[40];
    long int dni;
    int edad, flag;
};
int longitudPers;

struct persona* cargarPersona(struct persona *punteroPers, int longitudPers);
void buscarPersona(struct persona *punteroPers, int longitudPers);
void imprimirPersona(struct persona *punteroPers, int longitudPers);
struct persona *eliminarPersona(struct persona *punteroPers, int longitudPers);
struct persona *ordenarPersonas(struct persona *punteroPers, int longitudPers);            
void imprimrGrafico(struct persona *punteroPers, int longitudPers);

int main()
{
    int opcion;
    longitudPers=1;
    struct persona* punteroPers;
    punteroPers=malloc(sizeof(struct persona));
    if(punteroPers==NULL)
    {
        printf("\nNo hay lugar en la memoria\n");
        exit(0);
    }

    do
    {
        printf("Marque:\n1. Ingresar persona/s\n2. Buscar persona\n3. Eliminar persona de la lista\n4. Ordenar lista alfabeticamente\n5. Imprimir grafico de edades\n6. Salir de la agenda\n");
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion)
        {
        case 1:
            cargarPersona(punteroPers, longitudPers);
            break;
    
        case 2:
            buscarPersona(punteroPers, longitudPers);
            break;

        case 3:
            eliminarPersona(punteroPers, longitudPers);
            break;

        case 4:
            //ordenarPersonas(punteroPers, longitudPers);
            break;

        case 5:
            imprimrGrafico(punteroPers, longitudPers);
            break;
        }
        puts("---------------------------------------------------------------------------");
        fflush(stdin);
        
    } while (opcion!=6);
    free(punteroPers);
    return 0;
}

struct persona* cargarPersona(struct persona *punteroPers, int longitudPers)
{
    int option=1;
    int auxNuevaLogitud;
    struct persona* punteroAux;

    while(option==1)
    {
        printf("Datos de contacto:\n");
        printf("Ingrese apellido/s y nombre/s: ");
        scanf("%s", (punteroPers+longitudPers-1)->nombre);
        printf("Ingrese el DNI: ");
        scanf("%ld", &(punteroPers+longitudPers-1)->dni);
        printf("Ingrese la edad: ");
        scanf("%d", &(punteroPers+longitudPers-1)->edad );
        fflush(stdin);
        (punteroPers+longitudPers-1)->flag=0;

        printf("Si desea cargar otra persona ingrese 1 o para finalizar 2: ");
        scanf("%d", &option);
        
        if(option == 1)
        {
            auxNuevaLogitud = sizeof(struct persona) * longitudPers;
            // Redimencionamos la lista
            punteroAux = realloc( punteroPers, auxNuevaLogitud);
            if (punteroPers == NULL)
            {
                printf("\nNo hay lugar en memoria\n");
                break;
            }
            longitudPers++; //Incremento el contador de personas
            punteroPers = punteroAux;
        }
        else
        {
            break;
        }
    } 
    free(punteroAux);
    fflush(stdin);
    imprimirPersona(punteroPers, longitudPers);
    return punteroPers;
}

void buscarPersona(struct persona *punteroPers, int longitudPers)
{
    char contact[40];
    int bandera=0;
    printf("Ingrese apellido y nombre de la persona: ");

    gets(contact);
    for(int i=0; i<longitudPers; i++)
    {
        if(strcmp((punteroPers+i)->nombre, contact)==0 && (punteroPers+i)->flag==0)
        {
            imprimirPersona(punteroPers+i, 1);
            bandera=1;
        }
    }
    if(bandera==0)
    {
        printf("No se encontro el contacto\n");
    }
}

void imprimirPersona(struct persona *punteroPers, int longitudPers)
{
    for(int i=0; i<longitudPers; i++)
    {
        if((punteroPers+i)->flag==0)
        {
            puts("--------------------------------------------------");
            printf("Contacto:\n");
            printf("Apellido/s y Nombre/s: %s\n", (punteroPers+i)->nombre);
            printf("DNI: %ld\n", (punteroPers+i)->dni);
            printf("Edad: %d\n", (punteroPers+i)->edad);
        }
    }
}


struct persona *eliminarPersona(struct persona *punteroPers, int longitudPers)
{
    int i, bandera=0;
    char option;
    char name[40];
    printf("Ingrese el nombre del contacto a eliminar de la agenda: ");
    gets(name);

    for(i=0; i<longitudPers; i++)
    {
        if(strcmp((punteroPers+i)->nombre, name)==0)
        {
            imprimirPersona(punteroPers+i, 1);
            printf("Esta seguro de eliminarlo? (s/n) ");
            scanf(" %c", &option);
            if(option=='s'|| option=='S')
            {
                (punteroPers+i)->flag=1;
                printf("El contacto fue eliminado\n");
            }
            bandera=1;
        }
    }

    if(bandera==0)
    {
        printf("No se encontro el contacto\n");
    }
    
    return punteroPers;
}

/*struct persona *ordenarPersonas(struct persona *punteroPers, int longitudPers)
{
    struct persona *punteroAux;
    for(int i=0; i<longitudPers-1; i++)
    {
        for(int j=i+1; j<longitudPers; j++)
        {
            if(strcmp((punteroPers+i)->nombre, (punteroPers+j)->nombre)>0)
            {
                punteroAux=punteroPers[i];
                punteroPers[i]=punteroPers[j];
                punteroPers[j]=punteroAux;
            }
        }
    }

    printf("Agenda ordenada alfabeticamente\n");
    for(int i=0; i<longitudPers; i++)
    {
        if((punteroPers+i)->flag ==0)
        {
            imprimirPersona(punteroPers+i, 1);
        }
    }
    return punteroPers;
}*/

void imprimrGrafico(struct persona *punteroPers, int longitudPers)
{
    
    int i, j, mayor = 0, filas;
    int contadores[3];
    
    printf("\n----------------------------\
           \n  GRAFICO DE EDADES  \
           \n----------------------------\n");
    // Inicializo contadores en 0
    for (i = 0; i < 3; i++) {
        contadores[i] = 0;
    }
    // Recorro el array de personas y cuento cantidad de cada grupo de edades
    for (i = 0; i < longitudPers; i++) {
        if ((punteroPers+i)->edad < 19 && (punteroPers+i)->flag == 0) {
            contadores[0]++;
        }
        else {
            if ((punteroPers+i)->edad > 18 && (punteroPers+i)->edad < 36 && (punteroPers+i)->flag == 0) {
                contadores[1]++;
            }
            if ((punteroPers+i)->edad > 35 && (punteroPers+i)->flag == 0) {
                contadores[2]++;
            }
        } 
    } 
    // Encuentro el grupo de edades con mas personas registradas
    if (contadores[0] >= contadores[1] && contadores[0] >= contadores[2]) {
        mayor = contadores[0];
    }
    else {
        if (contadores[1] >= contadores[0] && contadores[1] >= contadores[2]) {
            mayor = contadores[1];
        }
        if (contadores[2] >= contadores[0] && contadores[2] >= contadores[1]){
            mayor = contadores[2];
        }
    }
    filas = mayor; // Declaro la cantidad de filas en base al grupo mayor
    //Imprimo el grafico
    for (i = 0; i < mayor; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            if (contadores[j] >= filas) 
            {
                printf("*");
                
            }
            else 
            {
                printf("");
            } 
        } 
        filas--;
        printf("\n");
    } // for (i = 0; i < mayor; i++)
    printf("<18 19-35 >35\n\n");
}
