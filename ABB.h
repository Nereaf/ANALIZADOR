#ifndef bosqueABB_H_
#define  bosqueABB_H_

typedef struct elemento
{
    char* lexema;
    int comLexico;
    int linea;

}elem;

//Funcion para insertar elementos indicando el lexema unicamente
elem* insertar( elem lex );

//Funcion para insertar indicando el lexema y el componente lexico
elem *insertarA(char *lexemaActual, int compLex);

//Funcion para borrar la memoria de la tabla de simbolos
int borrarTS( );

//Funcion para imprimir la tabla de simbolos
void imprimirTS( );

#endif 
