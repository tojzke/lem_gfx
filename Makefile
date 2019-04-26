
SRC = $(wildcard src/*.c)

INCLUDE = include

LIB_FOLDER = lib

MAIN_LIB = SDL2
IMG_LIB = SDL2_image
PRT_LIB = ftprintf

graph :
	gcc $(SRC) -I $(INCLUDE) -L $(LIB_FOLDER) -l$(MAIN_LIB) -l$(IMG_LIB) -l$(PRT_LIB)