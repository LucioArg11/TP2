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
int crear_archivo_nros();
int resultado_cadenas();
int es_multiplo_5(char *v,int *cont);
int es_multiplo_6(char *v,int *cont);
int crear_archivo_notas();
void cambio_de_pagina(FILE **pf);
float promedio_notas(float m[][6],int cant);



#endif // ACTUALIZACION_ARCHIVOS_H_INCLUDED
