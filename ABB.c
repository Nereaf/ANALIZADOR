#include "ABB.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
    elem elemento;
    struct Nodo *izq;
    struct Nodo *der;
}

void crear(abin *A)
{
	*A = NULL;
}

unsigned esVacio(abin A)
{
	return (A == NULL);
}

abin izq(abin A)
{
	return A->izq;
}

abin der(abin A)
{
	return A->der;
}

void leer(abin A, elem *E)
{
	*E = A->info;
}

void insertar(abin *A, elem E)
{
	if (esVacio(*A))
	{
		*A = (abin)malloc(sizeof(struct Nodo));
		(*A)->info = E;
		(*A)->izq = NULL;
		(*A)->der = NULL;
		return;
	}
	clave key = E.lexema;
	int result;
	if ((result = strcmp(key, (*A)->info.lexema)) > 0)
	{
		insertar(&(*A)->der, E);
	}
	else if (result < 0)
	{
		insertar(&(*A)->izq, E);
	}
}

void buscar_nodo(abin A, clave key, elem *E)
{
	int result;
	if (esVacio(A))
	{
		return;
	}
	if ((result = strcmp(key, A->info.lexema)) == 0)
	{
		*E = A->info;
	}
	else if (result < 0)
	{
		buscar_nodo(A->izq, key, E);
	}
	else
	{
		buscar_nodo(A->der, key, E);
	}
}

void destruir(abin *A)
{
	if (!esVacio(*A))
	{
		free((*A)->info.lexema);
		destruir(&((*A)->der));
		destruir(&((*A)->izq));
		free(*A);
		*A = NULL;
	}
}
