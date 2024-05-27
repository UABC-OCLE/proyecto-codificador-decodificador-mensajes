ASM_SOURCE = coder.asm
C_SOURCE = main.c
OBJ_FILES = main.o coder.o
EXEC_RELEASE = proyecto_release.bin
EXEC_DEBUG = proyecto_debug.bin

# Regla para la version de lanzamiento
release: $(OBJ_FILES)
		gcc -o $(EXEC_RELEASE) $(OBJ_FILES)

# Regla para la version de depuracion
debug: $(OBJ_FILES)
		gcc -g -o $(EXEC_DEBUG) $(OBJ_FILES)

# Regla para compilar el codigo fuente de C a objeto
main.o: $(C_SOURCE)
		gcc -c $(C_SOURCE)

# Regla para compilar el codigo fuente ASM a objeto
coder.o: $(ASM_SOURCE)
		nasm -f elf64 -o coder.o $(ASM_SOURCE)

# Limpieza de archivos generados
clean:
		rm -f $(OBJ_FILES) $(EXEC_RELEASE) $(EXEC_DEBUG)
