# Codificador / Decodificador

## Descripción

Este proyecto implementa un codificador/decodificador de mensajes utilizando el lenguaje de programación C y ensamblador (ASM). La aplicación permite ingresar un mensaje y codificarlo o decodificarlo utilizando un desplazamiento de posiciones especificado por el usuario. Las letras mayúsculas y minúsculas son desplazadas dentro de sus respectivos rangos, mientras que otros caracteres permanecen inalterados.

## Integrantes del Proyecto

- **Cazares Meraz Luis Diego**
- **Castro Campos Milton Manuel**
- **Vargas Gonzalez German**

## Características

- **Codificación y Decodificación**: Permite codificar o decodificar un mensaje basado en un número de posiciones especificado.
- **Soporte para Mayúsculas y Minúsculas**: Desplaza letras mayúsculas y minúsculas manteniéndolas en sus respectivos rangos.
- **Interfaz de Usuario en C**: Interfaz de consola con colores para una mejor experiencia de usuario.

## Instrucciones de Uso

1. **Clonar el Repositorio**:
    ```sh
    git clone https://github.com/tu-usuario/codificador-decodificador.git
    cd src
    ```

2. **Compilar el Código**:
    - Compila el código C y ensamblador con el Makefile:
      ```sh
      make release
      ```

3. **Ejecutar el Programa**:
    ```sh
    ./codificador
    ```

4. **Interacción con el Programa**:
    - Ingresa el mensaje a codificar o decodificar.
    - Especifica la cantidad de posiciones para el desplazamiento.
    - Indica `0` para codificar o `1` para decodificar.
    - El programa mostrará el mensaje resultante.

## Estructura del Proyecto

- `main.c`: Código principal en C que maneja la interacción con el usuario y llama a la función de codificación/decodificación.
- `codificar_decodificar.asm`: Implementación en ensamblador de la función de codificación y decodificación.
- `README.md`: Este archivo, que contiene la descripción y las instrucciones del proyecto.

## Ejemplo de Uso

```sh
Ingrese el mensaje: Hola Mundo
Ingrese la cantidad de posiciones: 3
Ingrese 0 para codificar o 1 para decodificar: 0
Resultado: Krñd Pxqgr
