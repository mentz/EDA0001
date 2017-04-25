#OBJS specifies which files to compile as part of the project
OBJS = complexo.c testaComplexo.c

#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lm 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = a.out

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(OBJS) -o $(OBJ_NAME) $(LINKER_FLAGS)
