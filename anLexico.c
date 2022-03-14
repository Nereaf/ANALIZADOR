#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABB.h"
#include "anLexico.h"
#include "sisEntr.h"
#include "ts.h"

//caracter actual a analizar
char now;

//variable para almacenar la línea en la que nos encontramos
int linea=1;


void analizaGeneralComments();
void analizaIdentificadores();
void analizaStringLiteral();

//función que devuelve el componente léxico apunta a un struct
elem siguienteComponenteLexico(){
    int flag=0;
    elem elemLexico;    
    char siguiente;
    while(flag==0){
        switch(now){
            // si se encuentra / se trata de un comentario
            case '/':
                now= siguienteCaracter();
                //comentario de línea
                if(now='/'){
                    while(now != '\n' && now!= 'EOF'){
                        now= siguienteCaracter();
                    }
                    linea+=1;
                    terminarLexema(0);
                }
                //com,entario general
                if(now='*'){
                    analizaGeneralComments();
                }
             break;

            //caracteres únicos que forman por sí mismos un componente léxico
            case '(': case ')': case '[': case ']':
            case '{':
            case  '}':
            case ',':
            case ';':
            case ':':
            break;
            //identificadores
            case 'A'...'Z':
            case 'a'..'z':
               analizaIdentificadores();
            break;
            case '\"':
            analizaStringLiteral;
            break;
            case '+':
            siguiente=siguienteCaracter();
                if(siguiente== '=' || siguiente =='+'){
                    elemLexico.lexema=terminarLexema();
                    if((elemLexico.comLexico=buscarLexema())==0){
                        elemLexico.comLexico = insertarLexema(elemLexico.lexema);
                    }
                }else{
                    elemLexico.lexema=terminarLexema(-1);
                    elemLexico.comLexico= (int)'+' ;
                }




            }
    }
}



//______________________________________COMENTARIOS GENERALES______________________________________

void analizaGeneralComments(){
    int flag=1;
    char siguiente;
    now=siguienteCaracter();
    siguiente=siguienteCaracter();
    while(flag){
        if(now='*' && siguiente='/'){
            //finComentario
            terminarLexema(0);
            now=siguiente;
            flag=0;
        }
        if(now='EOF' || siguiente= 'EOF'){
            //error
            flag=0;
        }else{
           
            now=siguiente;
            siguiente=siguienteCaracter();
        }
    }
}

//_______________________________________IDENTIFICADORES____________________________________________
void analizaIdentificadores(){
    //flag para parar el bucle en caso de que se encuentre un caracter distinto 
    int flag=1;
    elem elemento;
    int comLexico;
    while(flag){
        now=siguienteCaracter();
        switch (now) {
        //a partir del primer caracter ya pueden introducirse números como parte de los identificadores.
        case '0'...'9': case 'A'...'Z': case 'a'...'z': case '_':
            break;
        default:
            flag=0;
            //si se trata de otro caracter entonces indicaría que ya se termina el elemento del identificador.
            //TODO: reserva memoria
            elemento.elemento = terminarLexema(0);
            if((elemento.comLexico=buscarelemento())==0){
                elemento.comLexico = insertarelemento(elemento.lexema);
            }
            break;
        }
    }
}
//_______________________________________STRINGS LITERALS____________________________________________
elem analizaStringLiteral(){
    char siguiente= siguienteCaracter();
    int flag=1;
    elem elemento;
    //el string seguirá hasta encontrarse con la " de finalización pero tendremos la excepción de 
    //que se ecuentre \" lo quetratará " como un caracter literal.
    while(flag){
        if(siguiente!='\"' || (siguiente== '\"' && now='\\') ){
            if(sigiuente=='EOF'){
                flag=0;
            }
           else{
                now=siguiente;
                siguiente=siguienteCaracter();   
            } 
        } else{
            flag=0;
        }
    }

    if(siguiente=='EOF'){
        //error
    }else{
        elemento.lexema=terminarLexema(0);
         if((elemento.comLexico=buscarLexema())==0){
                elemento.comLexico = insertarLexema(elemento.lexema);
         }
    }
    return elemento;
}