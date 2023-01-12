#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define SIZE 1024
extern socket_cliente();
struct PDU
{
    char cabeza;
    char mensaje[100];
};
void enviar_archivo(FILE *archivo, int conexion){
    char data[SIZE] = {0};

    while(fgets(data, SIZE, archivo) != NULL){
        if(send(conexion, data, sizeof(data), 0) == -1){
            perror("Error enviando data");
            exit(1);
        }
        bzero(data, SIZE);
    }
}
main()
{
    //char nombreArchivo[25];
    char *nombreArchivo="archivo.txt";
    FILE *archivo;
    int conexion;
    struct PDU peticion, respuesta;
    printf("--------- INICIO DE CLIENTE --------\n");
    printf("Ingrese dato a enviar:");
    //scanf("%s", nombreArchivo);
    conexion = socket_cliente("10.0.2.15", 55055);
    archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL){
        perror("Error al leer el archivo");
        exit(1);
    }
    enviar_archivo(archivo, conexion);
    printf("Archivo enviado \n");
    //strcpy(peticion.mensaje, nombreArchivo);
    //write(conexion, &peticion, sizeof(peticion));
    //read(conexion, &respuesta, sizeof(respuesta));
    printf("RESPUESTA DE SERVIDOR: %s\n", respuesta.mensaje);
    close(conexion);
}