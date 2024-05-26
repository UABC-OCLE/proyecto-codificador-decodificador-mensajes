; Código en ASM

section .data
    mensaje db 'ingresa tu mensaje: ', 0
    mensaje_desplazamiento db 'ingresa la cantidad de desplazamiento: ', 0
    mensaje_salida db 'mensaje cifrado: ', 0
    mensaje_error db 'opcion invalida. saliendo.', 0
    nueva_linea db 10, 0

section .bss
    entrada resb 256 ; reservar espacio para el mensaje de entrada
    salida resb 256 ; reservar espacio para el mensaje de salida
    desplazamiento resb 4 ; reservar espacio para el valor de desplazamiento

section .text
    global _start

_start:
    ; leer el mensaje del usuario
    mov rax, 1
    mov rdi, 1
    mov rsi, mensaje
    mov rdx, 20
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, entrada
    mov rdx, 256
    syscall

    ; leer el valor de desplazamiento
    mov rax, 1
    mov rdi, 1
    mov rsi, mensaje_desplazamiento
    mov rdx, 30
    syscall

    mov rax, 0
    mov rdi, 0
    mov rsi, desplazamiento
    mov rdx, 4
    syscall

    ; convertir el valor de desplazamiento de ascii a numero
    sub byte [desplazamiento], '0'

    ; cifrar el mensaje
    mov rsi, entrada ; apunta al inicio del mensaje de entrada
    mov rdi, salida ; apunta al inicio del mensaje de salida
    mov cl, byte [desplazamiento] ; cargar el valor del desplazamiento

cifrado_bucle:
    lodsb ; cargar el siguiente byte de entrada en al
    test al, al ; comprobar si hemos llegado al final del string (byte nulo)
    jz hecho ; si es el final, saltar a hecho

    add al, cl ; desplazar el caracter
    stosb ; almacenar el caracter cifrado en salida
    jmp cifrado_bucle ; repetir para el siguiente caracter

hecho:
    ; imprimir el mensaje cifrado
    mov rax, 1
    mov rdi, 1
    mov rsi, mensaje_salida
    mov rdx, 16
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, salida
    mov rdx, 256
    syscall

    ; salir del programa
    mov rax, 60
    xor rdi, rdi
    syscall
