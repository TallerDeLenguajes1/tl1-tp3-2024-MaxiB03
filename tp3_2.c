#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define M 5
#define N 12

int main()
{
    srand(time(NULL));
    int mt[M][N],suma=0,prom, max=0, min=50001, anioMax, anioMin, mesMax, mesMin;

    //Inicializo la matriz
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            mt[i][j]=10000+rand()%40001;
            printf("%d\t", mt[i][j]);
        }
        printf("\n");
    }

    //promedio ganancia por anio
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            suma=suma+mt[i][j];
        }
        prom=suma/12;
        printf("Promedio de Ganancias en el anio %d: %d\n", i+1, prom);
        suma=0;
    }

    //Valor maximo y minimo obtenido
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mt[i][j]>=max)
            {
                max=mt[i][j];
                anioMax=i+1;
                mesMax=j+1;
            }

            if(mt[i][j]<=min)
            {
                min=mt[i][j];
                anioMin=i+1;
                mesMin=j+1;
            }
        }
    }
    printf("El valor Maximo es %d, en el anio %d y mes %d \n", max, anioMax, mesMax);
    printf("El valor Minimo es %d, en el anio %d y mes %d", min, anioMin, mesMin);

    return 0;
}