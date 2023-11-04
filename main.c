#include "cube3d.h"

int print_err(char *str)
{ // exit yapılması gerekmez mi
    printf("%s", str);
    return 1;
}

int main(int argc, char **argv)
{
    t_game *game;
    int i = 0; // free lemme işlemi için -> bunu sonra farklı 1 fonksiyonda yap

    if (argc != 2)
        return print_err("Wrong argument");
    game = malloc(sizeof(game));
    map_init(argv[1], game);
    while (i < game->map->map_Y)
    {
        free(game->map->map[i]);
        i++;
    }
    free(game->map);
    free(game);

    return 0;
}