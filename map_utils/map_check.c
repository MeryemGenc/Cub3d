#include "../cube3d.h"

int map_check(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->map_H)
    {
        j = 0;
        while (j < ft_strlen(map->map[i]))
        {
            printf("%c", map->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return (0);
}