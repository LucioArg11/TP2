#include "Vectores.h"

int* encuentra_elemento(int *v,int ele)
{
    while(*v && *v!=ele)
    {
        v++;
    }
    return *v? v:NULL;
}

int atoi(const char *numPtr)
{
    int valor=0;
    sscanf(numPtr,"%d",&valor);
    return valor==0?0:valor;

}

void miitoa(int nro, char *str)
{
    sprintf(str,"%d",nro);

}

long int atol(const char *str)
{
    long int valor=0;
    sscanf(str,"%ld",&valor);
    return valor==0?0:valor;
}

void primer_palabra(char *str,char *primer)
{
    while(*str!='.')
    {
        str++;
        *primer=*str;
    }
}

int cant_rep(const char *str,char *palabra)
{
    int coinsidencia=0,repes=0;
    while (*str)
    {
        while(*str!=*palabra)
        {
            str++;
        }
        while(*str==*palabra && *str!='.')
        {
            palabra++;
            coinsidencia++;
            palabra++;
        }
        if(*palabra=='.')
        {
            repes++;
            palabra=palabra-coinsidencia;
        }else
        {
            palabra=palabra-coinsidencia;
        }
    }
    return repes;
}

int cant_palabras(const char *str)
{
    int cont=0;
    while(*str)
    {
        while(*str!='.')
        {
            str++;
        }
        cont++;
        str++;
    }
    return cont;
}
