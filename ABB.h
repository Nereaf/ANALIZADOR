#ifndef bosqueABB_H_
#define  bosqueABB_H_


typedef struct elem{
    char* dato;
    int comLex;
    int linea;
}elem;


typedef char* clave;

typedef struct nodo* abb;

void crear(abb *A);

void leer(abb A, elemento *E);

void destruir(abb *A);

unsigned esVacio(abb A);

abb izq(abb A);

abb der(abb A);

void insertar(abb *A, elemento E);

void buscar_nodo(abb A, clave key, elemento *E);

#endif 
