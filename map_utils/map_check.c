#include "../cube3d.h"

    // game->map->map için yer ayır malloc ile (yer atamamıza gerek var mı - map e zaten splitte yer atanıyor.) - şiimdilik YOK diyelim
    // \n görene kadar her satırı map e ata.
    // game->map->map_X i olana kadar sonuna space koy.


int map_parsing(t_map *map, char *line)
{
    int i;
    int j;
    char **this_map;

    i = 0;
    j = 0;
    this_map = (char **)malloc(map->map_H * map->map_W);
    while(i < map->map_H)
    {
        j = 0; printf("1");
        // printf("\nmap %d. satir uzunluk: %d", i, (int)ft_strlen(map->map[i])); // 33 -> 32 
        // printf("\n%s", map->map[i]);
        while (j < map->map_H)
        {   //printf("3");
            if (j < (int)ft_strlen(map->map[i]) - 1)
                this_map[i][j] = map->map[i][j];
            else
                this_map[i][j] = '*';
            j++;
        }
        this_map[i][j] = '\0';
        i++;
    }
    map->map = map;

    int a = 0;
    printf("----------------------------  MAP  ------------------------------");
    while (a < map->map_H)
    {
        printf("\n%s", map->map[a]);
        a++;
    }
    free(line);
    return 0;
}