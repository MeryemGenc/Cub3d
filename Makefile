NAME = cub3d
CC = gcc

SOURCES = $(wildcard *.c  map/*.c libft/*.c libft/get_next_line/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
#CFLAGS =  -Iinclude -Iminilibx-macos -Isrc/libft 
CFLAGS =  -Iinclude -Ilibft 
#MLX = libmlx.a -framework OpenGL -framework AppKit

#-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) run_libft
	$(CC) $(OBJECTS) $(CFLAGS) $(MLX) -o $(NAME)

#run_mlx: run_libft
#	 cd minilibx-macos && $(MAKE) re
#	# mv minilibx-macos/libmlx.a ./

 run_libft:
 	cd libft && $(MAKE) re
 	mv libft/libft.a ./

clean:
	rm -f $(OBJECTS)
	cd libft && $(MAKE) fclean
#	cd minilibx-macos && $(MAKE) clean

fclean: clean
	rm -rf libft.a
	rm -rf $(NAME)
#	rm -rf libmlx.a

re: fclean all
