#ifndef ACTUALIZACION_ARCHIVOS_H_INCLUDED
#define ACTUALIZACION_ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char nombre [10];
    char apellido[10];
    double sueldo;
}t_Emple;

typedef struct
{
    int dni;
    char nombre [10];
    char apellido [10];
    float promedio;
}t_Alu;

int carga_archivo();
int lee_archivo();
int actualiza_archivos();
int abrir_archivo(FILE **pf,const char* nombrefile,const char* modo,const char* error);


#endif // ACTUALIZACION_ARCHIVOS_H_INCLUDED
