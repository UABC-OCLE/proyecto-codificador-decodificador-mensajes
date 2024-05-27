// Código en C
#include <stdio.h>
#include <string.h>

extern void codificar_decodificar(char *mensaje, int posiciones, int operacion);

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

int main() {
    char mensaje[100];
    int posiciones, operacion;

    printf(BOLD BLUE "-------------------------------------\n" RESET);
    printf(BOLD BLUE "- " WHITE "Codificador / Decodificador" BLUE " -\n" RESET);
    printf(BOLD BLUE "-------------------------------------\n" RESET);

    printf(BOLD GREEN "Ingrese el mensaje: " RESET);
    fgets(mensaje, sizeof(mensaje), stdin);
    mensaje[strcspn(mensaje, "\n")] = '\0'; 

    printf(BOLD GREEN "Ingrese la cantidad de posiciones: " RESET);
    scanf("%d", &posiciones);

    printf(BOLD GREEN "Ingrese " YELLOW "0" GREEN " para " RED "codificar" GREEN " o " YELLOW "1" GREEN " para " CYAN "decodificar" GREEN ": " RESET);
    scanf("%d", &operacion);

    codificar_decodificar(mensaje, posiciones, operacion);

    printf(BOLD BLUE "\n-------------------------------------\n" RESET);
    printf(BOLD BLUE "- " WHITE "Resultado: " YELLOW "%s" BLUE " -\n" RESET, mensaje);
    printf(BOLD BLUE "-------------------------------------\n" RESET);

    return 0;
}
