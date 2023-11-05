#include "cube3d.h"

// malloc kontrollerini yap - UNUTMA


int print_err(char *str)
{ // exit yapılması gerekmez mi
    printf("%s", str);
    return 1;
}

int main(int argc, char **argv)
{
    //t_game *game;
    t_map *map;

    //int i = 0; // free lemme işlemi için -> bunu sonra farklı 1 fonksiyonda yap

    if (argc != 2)
        return print_err("Wrong argument");
    //game = malloc(sizeof(game));
    map = (t_map *)malloc(sizeof(t_map *));
    map_init(argv[1], map);
    free(map);
    free(map->map);
    //free(game);

    return 0;
}