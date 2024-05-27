// Código en C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 256

// Llamar a las funciones externas de asm
extern void codificar_mensaje(char *cadena);
extern void decodificar_mensaje(char *cadena);
// Declaracion de los prototipos
void menu(int *opcion); /* Menu de seleccion para el usuario */
void codificarMensaje(char **ptr_Cadenas, int iCadenas); /* Ingreso de cadena y la codifica */
void decodificarMensajes(char **ptr_Cadenas, int iCadenas); /* Eleccion de la cadena almacenada que esta codificada y la descodifica */
void reSize(char ***ptr_Cadenas, int iCadenas); /* Aumenta en 1 el espacio del doble apuntador */
void freeMemory(char **ptr_Cadenas, int iCadenas); /* Libera la memoria del doble apuntador */
void waitForUser(); /* Esperar que el usuario dese continuar */

int main(void){
    // Declaracion de variables
    int opcion = 0;
    int iCadenas = 0;
    // Doble apuntador, para almacenas varios arreglos
    char **ptr_Cadenas = (char **)calloc(1, sizeof(char *)); 
    // Ciclo incial.
    while (opcion != 3){
        system("cls");
        system("clear");
        // Menu para el usuario
        menu(&opcion);
        // Eleccion del usuario
        switch(opcion)
        {
        case 1:
            // Verificamos que cuando no sea '0' haga un reSize al doble apuntador
            if (iCadenas != 0){
                reSize(&ptr_Cadenas, iCadenas);
            }
            // Funcion para codificar el mensaje
            codificarMensaje(ptr_Cadenas, iCadenas);
            // Aumentamos el tamaño del contador de cadenas.
            iCadenas++;
            break;
        case 2:
            // Funcion para decodificamos el mensaje
            decodificarMensajes(ptr_Cadenas,iCadenas);
            break;
        case 3:
            // Limpiamos consola
            system("cls");
            system("clear");
            // Salir
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Eleccion erronea, intenta de nuevo.\n\n");
            break;
        }
    }
    // Free la memoria
    freeMemory(ptr_Cadenas, iCadenas);
    // Forzamos la salida del programa
    return 0;
}

/* ########################################################################################## */

// Funcion para menu
void menu(int *opcion){
    // Menu de seleccion
    printf(" -- Codificador y Decodificador de mensajes --\n");
    printf("[1] - Codificar mensaje\n");
    printf("[2] - Decodificar mensaje\n");
    printf("[3] - Salir del programa\n");
    scanf("%d",opcion);
    getchar(); // Limpiar el buffer de entrada
    printf("\n");
}

// Funcion para codificar mensajes
void codificarMensaje(char **ptr_Cadenas, int iCadenas){
    // Declaracion de variables
    char strCadena[MAX_BUFFER];
    int len = 0;
    // Ingreso de la cadena a codificar
    do {
        // Limpiamos consola
        system("cls");
        system("clear");
        printf("Ingresa una cadena de caracteres a codificar: ");
        fflush(stdin); // Limpiar el búfer
        fgets(strCadena, sizeof(strCadena), stdin); // Tomar la cadena ingresada
        strCadena[strcspn(strCadena, "\n")] = '\0'; // Eliminar el carácter '\n'
    } while (strCadena[0] == '\0'); // Repetir si la cadena está vacía
    // Tomamos el tamaño del strCadena
    len = strlen(strCadena) + 1;
    // Hacemos resize al apuntador de cadenas.  
    ptr_Cadenas[iCadenas] = (char *) calloc(len, sizeof(char));
    // Mandamos a llamar al funcion externa .asm
    codificar_mensaje(strCadena);
    // Mostrar cadena modificada
    printf("\nCadena Codfiicada.\n");
    printf(">>>> %s\n", strCadena);
    waitForUser();
    // Ahora almacenamos strCadena en ptrCadenas, Cadenas ya codificadas
    strcpy(ptr_Cadenas[iCadenas], strCadena);
    // Limpiamos consola
    system("cls");
    system("clear");
}

// Funcion para Decodificar mensajes
void decodificarMensajes(char **ptr_Cadenas, int iCadenas){
    // Declaracion de variables
    int opcion = 0;
    char cadena[MAX_BUFFER];
    // Verificar si iCadenas esta vacia o llena
    if (iCadenas == 0){
        printf("No has codificado cadenas, intenta de nuevo\n\n");
        return;
    }
    // Verificar que solo este en el rango de iCadenas
    while (1)
    {
        // Borramos la consola
        system("cls");
        system("clear");
        // Imprimirmos las opciones
        for(int i=0; i<iCadenas; i++){
            printf("Cadena [%d]: %s\n",i + 1,ptr_Cadenas[i]);
        }
        // Selecciona la cadena
        printf("\nIngresa la cadena a decodificar: ");
        scanf("%d",&opcion);
        //
        if(opcion == 0 || opcion > iCadenas){
            printf("Error, rango inexistente.\n\n");
        }
        else{
            break;
        }
    }
    // Copeamos la cadena
    strcpy(cadena, ptr_Cadenas[opcion - 1]);
    // Decodificamos el mensaje
    decodificar_mensaje(cadena);
    // Imprimimos el manesaje ya decodificado;
    printf(">>>> %s\n\n", cadena);
    // Esperamos al usuario dese continuar.
    waitForUser();
    while (getchar() != '\n'); // Limpiar el buffer de entrada
}

// Funcion para aumentar el tamaño del doble apuntador
void reSize(char ***ptr_Cadenas, int iCadenas) {
    // Aumentamos el tamaño en uno del iCadenas
    iCadenas ++;
    // Aumentamos el espacio en 1 a temp.
    char **temp = realloc(*ptr_Cadenas, iCadenas * sizeof(char *));
    // En caso de que no se haya podido crear el espacio adicional.
    if (temp == NULL) {
        // Manejo del error: no se pudo redimensionar la memoria
        perror("No se pudo redimensionar la memoria");
        return;
    }
    // Se lo asignamos a original
    *ptr_Cadenas = temp;
    // Lo inicializamos en NULL para tenerlo limpio.
    for (int i = 0; i < iCadenas; ++i) {
        if ((*ptr_Cadenas)[i] == NULL) {
            (*ptr_Cadenas)[i] = NULL;
        }
    }
}

// Liberamos la memoria del doble apuntador
void freeMemory(char **ptr_Cadenas, int iCadenas){
    // Libera la memoria asignada
    for (int i = 0; i < iCadenas; ++i) {
        free(ptr_Cadenas[i]);
    }
    free(ptr_Cadenas);
}

void waitForUser() {
    // Declaracion de variables
    char c = '\0'; 
    do {
        printf("Press Enter to continue...");
        scanf("%c", &c);
        
    } while (c != '\n');
}
