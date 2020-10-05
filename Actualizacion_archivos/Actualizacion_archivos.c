#include "Actualizacion_archivos.h"
int carga_archivo()
{
    FILE *pf;
    t_Emple v[5]=
    {
        {48521536,"Nestor","Jose",2000},
        {45725538,"Carlos","Martin",4000},
        {25521571,"Karina","Diaz",8000},
        {24526536,"Maria","Rodriguez",2500},
        {29544436,"Ciro","Diaz",2880},
    };
    t_Alu v2[5]=
    {
        {48521536,"Nestor","Jose",6.5},
        {45725538,"Carlos","Martin",4},
        {25521571,"Karina","Diaz",7},
        {24526536,"Maria","Rodriguez",8.5},
        {29544436,"Ciro","Diaz",9.5}
    };
    pf=fopen("Empleados.dat","wb");

    if(!pf)
        return 0;

    fwrite(v,sizeof(t_Emple),5,pf);
    fclose(pf);

    pf=fopen("Alumnos.dat","wb");
    if(!pf)
        return 0;

    fwrite(v2,sizeof(t_Alu),5,pf);
    fclose(pf);
    return 1;
}

int lee_archivo()
{
    FILE *pf;
    t_Emple emple;
    t_Alu alu;

    pf=fopen("Empleados.dat","rb");
    if(!pf)
        return 0;

    printf("--------------------Empleados-----------------\n");

    fread(&emple,sizeof(t_Emple),1,pf);
    printf("DNI:%6d |Apellido: %12s | Nombre: %8s | Sueldo: %6.2f \n",emple.dni,emple.apellido,emple.nombre,emple.sueldo);
    while(!feof(pf))
    {

        fread(&emple,sizeof(t_Emple),1,pf);
        printf("DNI:%6d |Apellido: %12s | Nombre: %8s | Sueldo: %6.2f \n",emple.dni,emple.apellido,emple.nombre,emple.sueldo);
    }
    fclose(pf);

    printf("--------------------Alumnos-----------------\n");

    pf=fopen("Alumnos.dat","rb");
    if(!pf)
        return 0;

    fread(&alu,sizeof(t_Alu),1,pf);
    printf("DNI:%6d |Apellido: %12s | Nombre: %8s | Promedio: %6.2f \n",alu.dni,alu.apellido,alu.nombre,alu.promedio);

    while(!feof(pf))
    {
        fread(&alu,sizeof(t_Alu),1,pf);
        printf("DNI:%6d |Apellido: %12s | Nombre: %8s | Promedio: %6.2f \n",alu.dni,alu.apellido,alu.nombre,alu.promedio);
    }
    fclose(pf);

    return 1;


}

int actualiza_archivos()
{
    FILE *pf,*pf2;
    t_Emple emple;
    t_Alu alu;

    pf=fopen("Empleados.dat","r+b");
    if(!pf)
        return 0;

    pf2=fopen("Alumnos.dat","rb");
    if(!pf2)
        return 0;


    fread(&emple,sizeof(t_Emple),1,pf);
    fread(&alu,sizeof(t_Alu),1,pf2);

    while(!feof(pf))
    {
        if(emple.dni==alu.dni && alu.promedio>7)
        {
            emple.sueldo+=(emple.sueldo*7.28)/100;
            fseek(pf,(long)-sizeof(t_Emple), SEEK_CUR);
            fwrite(&emple,sizeof(t_Emple),1,pf);
            fseek(pf,0, SEEK_CUR);
            fread(&emple,sizeof(t_Emple),1,pf);
            fread(&alu,sizeof(t_Alu),1,pf2);
        }
        else if(emple.dni>alu.dni)
            fread(&emple,sizeof(t_Emple),1,pf);
            else
            fread(&alu,sizeof(t_Alu),1,pf2);
    }

    return 1;

}

int abrir_archivo(FILE **pf,const char* nombrefile,const char* modo,const char* error)
{
    *pf=fopen(nombrefile,modo);
    if(!*pf)
    {
        puts(error);
        return 0;
    }
    return 1;
}

int crear_archivo_nros()
{
    FILE *pf;
    int i=abrir_archivo(&pf,"Numeros.txt","wt","Error apertura de archivo");
    short int var=0;
    int uno=0,siete=0,lineas=0;

    if(i==0)
        return 0;
    fprintf(pf,"%6d %6d %6d %6d %6d %6d %6d\n",123456,123456,123456,123456,123456,123456,123456);
    while(uno!=1 || siete!=1)
    {
        var=rand()%(8-1)+1;
        for(i=0;i<var;i++)
        {
            fprintf(pf,"%6d ",(short int)rand());
        }
        fprintf(pf,"\n");
        lineas++;
        if(var==1)
            uno=1;
        if(var==7)
            siete=1;
    }
    fclose(pf);
    return lineas;
}

int resultado_cadenas()
{
    FILE *pf;
    int i=abrir_archivo(&pf,"Numeros.txt","rt","Error apertura de archivo");
    char nro[7];
    fseek(pf,(long)(sizeof(nro)*7+2),1);
    while(!feof(pf))
    {
        fscanf(pf,"%6s ",nro);
    }

}
