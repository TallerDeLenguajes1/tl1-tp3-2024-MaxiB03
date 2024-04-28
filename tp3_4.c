#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define tama 50

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef producto;

struct Cliente {
    int ClienteID;   //Numerado en el ciclo iterativo
    char *NombreCliente;   //Ingresado por usuario
    int CantidadProductosAPedir;   //(aleatorio entre 1 y 5)
    producto *Productos;   //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}typedef cliente;

void cargarCliente(cliente *pcliente, int cant);
void mostrarCliente(cliente *pcliente, int cant);

int main()
{
    srand(time(NULL));
    int cant;
    cliente *pcliente;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cant);

    pcliente=malloc(cant*sizeof(cliente));

    cargarCliente(pcliente, cant);
    mostrarCliente(pcliente, cant);

    return 0;
}

void cargarCliente(cliente *pcliente, int cant)
{
    char buff[tama];

    for (int i=0;i<cant;i++)
    {
        printf("\n---------- Cargar datos del cliente [%d] ----------\n", i+1);

        //Cargar ID
        pcliente->ClienteID=i+1;
        printf("ID cliente: %d\n", pcliente->ClienteID);
        
        //Cargar Nombre
        fflush(stdin);
        printf("Ingrese nombre del cliente: ");
        gets(buff);
        pcliente->NombreCliente=malloc((strlen(buff)+1)*sizeof(char));
        strcpy(pcliente->NombreCliente, buff);

        //Cargar cant de productos
        pcliente->CantidadProductosAPedir=1+rand()%5;
        printf("Cantidad de productos a pedir: %d\n", pcliente->CantidadProductosAPedir);

        //Cargar datos del producto
        pcliente->Productos=malloc(pcliente->CantidadProductosAPedir*sizeof(producto));
        for (int j=0;j<pcliente->CantidadProductosAPedir;j++)
        {
            pcliente->Productos[j].ProductoID=j+1;
            pcliente->Productos[j].Cantidad=1+rand()%10;
            pcliente->Productos[j].TipoProducto=TiposProductos[rand()%4];
            pcliente->Productos[j].PrecioUnitario=10+rand()%91;
        }
        pcliente++;   
    }
}

void mostrarCliente(cliente *pcliente, int cant)
{
    for (int i=0;i<cant;i++)
    {
        printf("\n---------- Datos del cliente [%d] ----------\n", i+1);
        printf("ID cliente: %d\n", pcliente->ClienteID);
        printf("Nombre del cliente: %s\n", pcliente->NombreCliente);
        printf("Cantidad de productos pedidos: %d\n", pcliente->CantidadProductosAPedir);

        for (int j=0;j<pcliente->CantidadProductosAPedir;j++)
        {
            printf("------ Producto Nro %d: %s \n", j+1, pcliente->Productos[j].TipoProducto);
            printf("ID producto: %d\n", pcliente->Productos[j].ProductoID);
            printf("Cantidad: %d\n", pcliente->Productos[j].Cantidad);
            printf("Precio Unitario: %.2f\n", pcliente->Productos[j].PrecioUnitario);
        }
        pcliente++;
    }
}