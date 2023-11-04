#include "cube3d.h"

int map_parsing(t_game *game, char *map)
{
    int i;
    int j;
    char **tmp_map;

    i = 0;
    tmp_map = ft_split(map, '\n');
    free(map);

    while(i < game->map.map_X)
    {
        printf("%s", tmp_map[i]);
        i++;
    }
}