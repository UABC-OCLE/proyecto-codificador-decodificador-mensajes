section .text                               ; Seccion de codigo de texto para codificar y decodificar mensajes
global codificar_mensaje                    ; Funcion Global, para que el main.c pueda tomarla
global decodificar_mensaje                  ; Funcion Global, para que el main.c pueda tomarla

                                            ; /* Inicio del codigo para Codificar */
codificar_mensaje:
    xor rcx, rcx                            ; Inicializar contador

codificar_loop:
    mov al, [rdi + rcx]                     ; Cargar el caracter actual en 'al'
    cmp byte [rdi+rcx], 0                   ; Verifica si es el fin de la cadena
    je codificar_fin                        ; Si es así, salta al final
    add al, 3                               ; Cifrado César
    mov [rdi + rcx], al                     ; Escribir el caracter cifrado de vuelta en la cadena
    inc rcx                                 ; Avanzar al siguiente carácter
    jmp codificar_loop                      ; Repetir el bucle

codificar_fin:
    ret                                     ; Regresa al main.c


                                            ; /* Inicio del codigo para Descodificar */
decodificar_mensaje:
    xor rcx, rcx                            ; Inicializar contador

decodificar_loop:
    mov al, [rdi + rcx]                     ; Cargar el caracter actual en 'al'
    cmp byte [rdi+rcx], 0                   ; Verifica si es el fin de la cadena
    je decodificar_fin                      ; Si es así, salta al final
    sub al, 3                               ; Descifrado César
    mov [rdi + rcx], al                     ; Escribir el caracter descifrado de vuelta en la cadena
    inc rcx                                 ; Avanzar al siguiente carácter
    jmp decodificar_loop                    ; Repetir el bucle

decodificar_fin:
    ret                                     ; Regresa al main.c
