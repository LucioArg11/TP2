#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define REDONDEA(X) (X-(int)X>0.5?(int)X+1:(int)X)
#define MENOR(X,Y) (X<Y?X:Y)
#define INTERCAMBIA(X,Y){ \
    int aux;\
    aux=*X; \
    *X=*Y;  \
    *Y=aux; \
}

int* encuentra_elemento(int *v,int ele);
int atoi(const char *numPtr);
void miitoa(int nro, char *str);
long int atol(const char *str);
void primer_palabra(char *str,char *primer);
int cant_rep(const char *str,char *palabra);
int cant_palabras(const char *str);

#endif // VECTORES_H_INCLUDED
