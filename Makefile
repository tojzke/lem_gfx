CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = lem-gfx



_SRC =	init_sdl.c \
		links.c \
		load_tools.c \
		main.c \
		node.c \
		read_rooms.c \
		read.c \
		steps.c \
		surfaces.c \
		tools.c \
		draw.c \
		draw_ants.c \
		dbg_tools.c \
		moving_ants.c \
		finished_ants.c

SRC = $(addprefix src/,$(_SRC))

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

INCLUDE = include

LIB_DIR = lib

MAIN_LIB = SDL2
IMG_LIB = SDL2_image
GFX_LIB = SDL2_gfx
TTF_LIB = SDL2_ttf
PRT_LIB = ftprintf
FT_LIB_DIR = libft
FT_LIB = ft

#Map should be red from stdin
MAP = 



$(NAME) : $(OBJ) 
	gcc -o $(NAME) $(OBJ) -I $(INCLUDE) -L $(LIB_DIR) -l$(MAIN_LIB) -l$(IMG_LIB) -l$(TTF_LIB) \
	-l$(PRT_LIB) -L$(FT_LIB_DIR) -l$(FT_LIB)

obj/%.o: src/%.c $(INCLUDE)/*.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean:
	rm -rf obj/

fclean: clean
	rm $(NAME)

#Run it like "make run MAP=<map_name>"
run : 
	./lem-in < $(MAP) | $(addprefix ./, $(NAME))