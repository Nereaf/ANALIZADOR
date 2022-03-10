#include "ABB.h"
#include "definiciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct celda ;
typedef struct celda
{
    elem info;
    struct celda *izq, *der;
}Nodo;

Nodo *ABB;


//Funcion para recorrer recursivamente el arbol e insertar la celda 
elem *insertarRecursivo(Nodo **celdaActual, char *lexemaActual, int compLex)
{
    //Si la celda actual no se encuentra vacia
    if (*celdaActual != NULL)
    {
        int resultado;
        //Si el lexema es el mismo que el de la celda
        if ((resultado = strcmp(lexemaActual, (*celdaActual)->info.lexema)) == 0)
        {
            //Devolvemos el elemento
            return &((*celdaActual)->info);
        }
        //En caso de que se encuentre a la izquierda
        else if (resultado < 0)
        {
            //Llamamos recursivamente a la funcion indicando la celda izquierda
            return insertarRecursivo(&(*celdaActual)->izq, lexemaActual, compLex);
        }
        //En caso de que se encuentre a la derecha
        else if (resultado > 0)
        {
            //Llamamos recursivamente a la funcion indicando la celda derecha
            return insertarRecursivo(&(*celdaActual)->der, lexemaActual, compLex);
        }
    }

    //En el caso de que la celda actual se encuentre vacia
    //Se inicializa una celda nueva
    *celdaActual = (Nodo *)malloc(sizeof(Nodo));

    //Se reserva memoria para el lexema indicado
    (*celdaActual)->info.lexema = (char *)malloc(sizeof(char) * strlen(lexemaActual));

    //Se copia el lexema
    strcpy((*celdaActual)->info.lexema, lexemaActual);

    //Actualizamos la informacion
    (*celdaActual)->info.comLexico = compLex;
    (*celdaActual)->der = NULL;
    (*celdaActual)->izq = NULL;

    //Devolvemos el elemento
    return &((*celdaActual)->info);
}
elem *insertar(elem lex)
{
    //Insertamos un elemento y cambiamos su informacion
    elem *l = insertarA(lex.lexema, lex.comLexico);


    return l;
}

//Funcion recursiva para liberar la memoria del arbol
void borrarRecursivo(Nodo *celda)
{
    //Recorremos la celdas de izquierda a derecha recursivamente
    if (celda->izq != NULL)
    {
        borrarRecursivo(celda->izq);
    }

    if (celda->der != NULL)
    {
        borrarRecursivo(celda->der);
    }

    //Liberamos la memoria del lexema y de la celda
    free(celda->info.lexema);
    free(celda);
}

int borrarABB()
{
    borrarRecursivo(ABB);
    return 0;
}

//Funcion recursiva para imprimir los lexema y los valores de las constantes y variables
void imprimirRecursivo(Nodo *celda)
{
    //Imprimimos de izquierda a derecha
    if (celda->izq != NULL)
    {
        imprimirRecursivo(celda->izq);
    }

    if (celda->der != NULL)
    {
        imprimirRecursivo(celda->der);
    }

    //Si el elemento es una variable o constante imprimimos tambien su valor numerico
    if (celda->info.comLexico == VAR_I || celda->info.comLexico == CONST_I)
    {
        //printf("\t%s = %.10g\n", celda->info.lexema, celda->info.valor.numero);
		 printf("\t%s\n", celda->info.lexema);
    }

    //Para todos los demas casos solo imprimimos el lexema
    else
    {
        printf("\t%s\n", celda->info.lexema);
    }
    return;
}

void imprimirABB()
{
    printf("Arbol abb\n");
    imprimirRecursivo(ABB);
}