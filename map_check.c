#include "cube3d.h"

    // game->map->map için yer ayır malloc ile (yer atamamıza gerek var mı - map e zaten splitte yer atanıyor.) - şiimdilik YOK diyelim
    // \n görene kadar her satırı map e ata.
    // game->map->map_X i olana kadar sonuna space koy.
int map_parsing(t_game *game)
{
    int i;
    int j;
    char **map;

    i = 0;
    j = 0;
    map = (char **)malloc(game->map->map_X * game->map->map_X);
    while(i < game->map->map_Y)
    {
        j = 0;
        printf("\nmap %d. satir uzunluk: %d", i, (int)ft_strlen(game->map->map[i])); // 33 -> 32 
        while (j < game->map->map_X)
        {
            if (j < ft_strlen(game->map->map[i]) - 1)
                map[i][j] = game->map->map[i][j];
            else
                map[i][j] = '*';
            j++;
        }
        map[i][j] = '\0';
        free(game->map->map[i]);
        i++;
    }
    free(game->map->map);
    game->map->map = map;

    int a = 0;
    printf("----------------------------------------------------------");
    while (a < game->map->map_Y)
    {
        printf("\n%s",game->map->map[a]);
        a++;
    }
    
    return 0;
}