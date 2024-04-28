#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *v[5], buff[100];

    for (int i=0;i<5;i++)
    {
        printf("Ingrese el nombre %d: ", i+1);
        gets(buff);

        v[i]=malloc((strlen(buff)+1)*sizeof(char));
        strcpy(v[i], buff);
    }

    printf("\n-----Listado de Nombres-----\n");
    for (int i=0;i<5;i++)
    {
        puts(v[i]);
    }

    for (int i=0;i<5;i++)
    {
        free(v[i]);
    }
    
    return 0;
}