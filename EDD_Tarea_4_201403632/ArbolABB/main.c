#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct NodoABB{
    int Id;
    struct NodoABB *Izq;
    struct NodoABB *Der;
}NodoABB;

typedef NodoABB *ArbolABB;
FILE* archivo;
void InsertarArbolABB (ArbolABB *raiz, int Id);
void MostrarArbol (ArbolABB raiz);


int main (){

    ArbolABB abb = NULL;
     int Opcion;
     int Numero;
      printf("\n| Universidad de San Carlos de Guatemala |");
      printf("\n|        Facultad de Ingenieria          |");
      printf("\n|         Estructuras de Datos           |");
      printf("\n|             Seccion: B                 |");
      printf("\n|       Jorge David Espina Molina        |");
      printf("\n|              201403632                 |");
      printf("\n|         Segundo Semestre 2018          |");
      printf("\n|              Tarea #4                  |");
      printf("\n\n");
      do{
              printf("|******************Menu******************|\n");
              printf("|     1.- Agregar                        |\n");
              printf("|     2.- Mostrar Arbol ABB              |\n");
              printf("|     3.- Salir                          |\n");
              printf("|                                        |\n");
              printf("|     Introduzca su Opcion (1-3)         |\n");
              printf("******************************************\n\n");
              scanf("%d",&Opcion);
               switch(Opcion){
                  case 1:
                   printf("Ingrese numero: \n");
                      scanf("%d", &Numero);
                      InsertarArbolABB (&abb, Numero);
                    break;
                  case 2:
                        MostrarArbol (abb);
                    break;

                                }
     }while(Opcion  < 4);





return 0;
}

void InsertarArbolABB (ArbolABB *raiz, int Id){
    if (*raiz == NULL){                             // SI MI ARBOL ES NULL ENTONCES CREAMOS MI NODO RAIZ
        *raiz = (NodoABB*)malloc(sizeof(NodoABB));
        (*raiz)->Id = Id;
        (*raiz)->Izq = NULL;
        (*raiz)->Der = NULL;
    }else{
        if (Id > (*raiz)->Id){                      // SI NO, VERIFICAMOS SI EL DATO INGRESADO ES MAYOR A RAIZ ACTUAL
            InsertarArbolABB(&(*raiz)->Der, Id);    // SI ES MAYOR LO AGREGAMOS A LA RAMA DERECHA
        }else if(Id < (*raiz)->Id){
            InsertarArbolABB(&(*raiz)->Izq, Id);    // SI NO LO AGREGAMOS A LA RAMA IZQUIERDA
        }else{
            printf("repetido\n");
        }
    }
}
void MostrarArbol(ArbolABB raiz){
    if (raiz != NULL){
        MostrarArbol (raiz->Izq);
        printf ("%d, ", raiz->Id);
        MostrarArbol (raiz->Der);
        }
}




