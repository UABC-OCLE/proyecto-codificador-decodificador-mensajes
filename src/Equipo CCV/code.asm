section .text
global codificar_decodificar

; Función codificar_decodificar
; Argumentos:
;   rdi: puntero al mensaje
;   rsi: cantidad de posiciones
;   rdx: 0 para codificar, 1 para decodificar
codificar_decodificar:
    xor rcx, rcx        ; Inicializar contador

loop:
    mov al, byte [rdi + rcx]   ; Cargar byte del mensaje
    cmp al, 0                  ; ¿Fin de cadena?
    je fin                     ; Si, terminar
    cmp al, 'A'                ; ¿Letra mayúscula?
    jl minuscula               ; No, comprobar minúscula
    cmp al, 'Z'
    jg minuscula               ; No, comprobar minúscula
    ; Letra mayúscula
    sub al, 'A'                ; Normalizar a 0
    cmp rdx, 0                 ; ¿Codificar?
    je codificar_mayuscula     ; Si, codificar
    ; Decodificar mayúscula
    mov r8, rsi                ; Copiar posiciones en r8
    neg r8                     ; r8 = -posiciones
    add al, r8b                ; Sumar -posiciones
    and eax, 0x0000001F        ; Aplicar módulo 26
    add al, 'A'                ; Restaurar mayúscula
    jmp guardar
codificar_mayuscula:
    add al, sil                ; Sumar posiciones
    and eax, 0x0000001F        ; Aplicar módulo 26
    add al, 'A'                ; Restaurar mayúscula
    jmp guardar
minuscula:
    cmp al, 'a'                ; ¿Letra minúscula?
    jl no_letra                ; No, pasar al siguiente byte
    cmp al, 'z'
    jg no_letra                ; No, pasar al siguiente byte
    ; Letra minúscula
    sub al, 'a'                ; Normalizar a 0
    cmp rdx, 0                 ; ¿Codificar?
    je codificar_minuscula     ; Si, codificar
    ; Decodificar minúscula
    mov r8, rsi                ; Copiar posiciones en r8
    neg r8                     ; r8 = -posiciones
    add al, r8b                ; Sumar -posiciones
    and eax, 0x0000001F        ; Aplicar módulo 26
    add al, 'a'                ; Restaurar minúscula
    jmp guardar
codificar_minuscula:
    add al, sil                ; Sumar posiciones
    and eax, 0x0000001F        ; Aplicar módulo 26
    add al, 'a'                ; Restaurar minúscula
    jmp guardar
no_letra:
    mov byte [rdi + rcx], al   ; Guardar byte sin modificar
    inc rcx                    ; Siguiente byte
    jmp loop
guardar:
    mov byte [rdi + rcx], al   ; Guardar byte modificado
    inc rcx                    ; Siguiente byte
    jmp loop
fin:
    ret
