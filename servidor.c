#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define SIZE 1024
extern acepta_conexion();
extern call_on_sock();
struct PDU
{
    char cabeza;
    char mensaje[100];
};
void escribir_archivo(int conexion)
{
    int n;
    FILE *archivo;
    char *nombreArchivo = "archivoRecibido.txt";
    char buffer[SIZE];
    archivo = fopen(nombreArchivo, "w+");
    if (archivo == NULL)
    {
        perror("Error al crear el archivo");
        exit(1);
    }
    while (1)
    {   
        n = recv(conexion, buffer, SIZE, 0);
        if (n <= 0)
        {
            break;
            return;
        }
        perror("Error a crear el archivo");
        printf("aa %s", buffer);
        fprintf(archivo, "%s", buffer);
        bzero(buffer, SIZE);
    }
    fclose(archivo);
    return;
}
main()
{
    int dirlisten, conexion;
    struct PDU peticion, respuesta;
    dirlisten = socket_servidor(55055);
    printf("--------- INICIO DEL SERVIDOR ----------\n");
    while (1)
    {
        while ((conexion = acepta_conexion(dirlisten)) < 0)
            ;
        // read(conexion, &peticion, sizeof(peticion));
        escribir_archivo(conexion);
        printf("Archivo transferido");
        printf("Escuchando .... ");
        strcpy(respuesta.mensaje, "Mensaje recibido");
        // write(conexion, &respuesta, sizeof(respuesta));
        close(conexion);
    }
}