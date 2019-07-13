
SRC = $(wildcard src/*.c)

INCLUDE = include

LIB_DIR = lib

MAIN_LIB = SDL2
IMG_LIB = SDL2_image
PRT_LIB = ftprintf
FT_LIB_DIR = libft
FT_LIB = ft

graph :
	gcc $(SRC) -I $(INCLUDE) -L $(LIB_DIR) -l$(MAIN_LIB) -l$(IMG_LIB) -l$(PRT_LIB) -L$(FT_LIB_DIR) -l$(FT_LIB)