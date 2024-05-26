#include "funciones.h"
#include <string.h>

// funcion para cifrar o descifrar usando cifrado cesar
void cifradoCesar(char *entrada, char *salida, int desplazamiento, int modo) {
    for (int i = 0; i < strlen(entrada); i++) {
        if (modo == 1) {
            salida[i] = entrada[i] + desplazamiento; // cifrar
        } else {
            salida[i] = entrada[i] - desplazamiento; // descifrar
        }
    }
    salida[strlen(entrada)] = '\0'; // terminar el string cifrado/descifrado
}
