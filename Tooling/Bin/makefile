#Rule: Dependencies
#	Action

C_COMPILER := gcc

C_FILES := ../Example.c
C_FILES += ../Func.c

OBJ_FILES := Example.o
OBJ_FILES += Func.o

EXE_FILE := main.exe

all: clean linking

build: $(C_FILES)
	@echo "Starting to build files"
	@$(C_COMPILER) -c $(C_FILES)

linking: build
	@echo "Linking object files"
	@$(C_COMPILER) $(OBJ_FILES) -o $(EXE_FILE)
	@echo "exe file generated"

clean:
	@rm -rf *.o *.exe