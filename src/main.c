// Código en C

#include <stdio.h>
#include "funciones.h"
#include <string.h>

int main() {
    char entrada[256];
    char salida[256];
    int desplazamiento;
    int modo;

    // leer el mensaje del usuario
    printf("Ingresa el mensaje: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0; // eliminar el salto de linea

    // leer el valor del desplazamiento
    printf("Ingresa el numero de posiciones para el cifrado cesar: ");
    scanf("%d", &desplazamiento);

    // leer la opcion de cifrar o descifrar
    printf("Ingresa 1 para cifrar o 2 para descifrar: ");
    scanf("%d", &modo);

    // llamar a la funcion de cifrado/descifrado
    cifradoCesar(entrada, salida, desplazamiento, modo);

    // imprimir el mensaje resultante
    printf("Mensaje resultante: %s\n", salida);

    return 0;
}
