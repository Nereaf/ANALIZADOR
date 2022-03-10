//inicia structura de datos, crea tabla de símbolos con palabras reservadas
#include "ABB.h"
#include <stdio.h>

#include <stdlib.h>

int main (){
    abb a;
    crear(&a);
    printf("hola mundo \n");
    printf("\n creamos elemento 1....\n");
    elem e;
    e.dato= (char *) malloc(5*sizeof(char));
    e.dato = "ho";
    e.comLex=5;
    e.linea=5;
      printf("\n creamos elemento 2....\n");
    elem f;
    e.dato= (char *) malloc(5*sizeof(char));
    e.dato = "ha";
    e.comLex=5;
    e.linea=65;
      printf("\n creamos elemento 3....\n");
    elem g;
    e.dato= (char *) malloc(5*sizeof(char));
    e.dato = "hz";
    e.comLex=5;
    e.linea=65;
      printf("\n insertamos....\n");
    insertar(&a, e);
    insertar(&a, f);
    insertar(&a, g);
    elem k;
          printf("\n buscamos....\n");
    buscar_nodo(a, "ho",&k);
    printf("%d", k.linea);
    printf("Es vacio? ");
    esVacio(a);
    elem l;
    leer(der(a),&l);
    printf("\n Destruyendo....\n");
    destruir(&a);

}













//finaliza, limpia memoria y sale
