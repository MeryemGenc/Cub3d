#include "cube3d.h"

int print_err(char *str)
{ // exit yapılması gerekmez mi
    printf("%s", str);
    return 1;
}

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2)
        return print_err("Wrong argument");
    game = malloc(sizeof(game));
    map_init(argv[1], game);

    return 0;
}