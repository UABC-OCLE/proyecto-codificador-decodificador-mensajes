// Código en C

#include <stdio.h>
#include <string.h>

extern void codificar_decodificar(char *mensaje, int posiciones, int operacion);

int main() {
    char mensaje[100];
    int posiciones, operacion;

    printf("Ingrese el mensaje: ");
    fgets(mensaje, sizeof(mensaje), stdin);
    mensaje[strcspn(mensaje, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingrese la cantidad de posiciones: ");
    scanf("%d", &posiciones);

    printf("Ingrese 0 para codificar o 1 para decodificar: ");
    scanf("%d", &operacion);

    codificar_decodificar(mensaje, posiciones, operacion);

    printf("Resultado: %s\n", mensaje);

    return 0;
}