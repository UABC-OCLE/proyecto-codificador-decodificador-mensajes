
ASM_SOURCE=code.asm
C_SOURCES=main.c 
OBJ_FILES=main.o code.o
EXEC_RELEASE=cifrador.bin

release: $(OBJ_FILES)
	gcc -no-pie -o $(EXEC_RELEASE) $(OBJ_FILES)

# Regla para ensamblar el código fuente ASM a objeto
code.o: $(ASM_SOURCE)
	nasm -f elf64 -o code.o $(ASM_SOURCE)

# Regla para compilar el código fuente C a objeto
main.o: $(C_SOURCES)
	gcc -c -o main.o $(C_SOURCES)

# Limpieza de archivos generados
clean:
	rm -f $(OBJ_FILES) $(EXEC_RELEASE)
