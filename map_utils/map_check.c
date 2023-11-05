#include "../cube3d.h"

    // game->map->map için yer ayır malloc ile (yer atamamıza gerek var mı - map e zaten splitte yer atanıyor.) - şiimdilik YOK diyelim
    // \n görene kadar her satırı map e ata.
    // game->map->map_X i olana kadar sonuna space koy.



/*int map_parsing(t_map *map, char *line)
{
    printf("sgrgsd");
    int i;
    int j;
    int indx;
    char **this_map;

    i = 0;
    j = 0;
    indx = 0;
    printf("kkkkkkkkkk");
    this_map = (char **)ft_calloc((map->map_H * map->map_W), sizeof(char)); // buranın tamı tamına ayırıldığına emin ol
    while(i < map->map_H)
    {
        j = 0; 
        printf("1");
        while (line[indx] && line[indx] != '\n')
        {   
            printf("%c", line[indx]);
            this_map[i][j] = line[indx];
            j++;
            indx++;
        }
        // while (j < map->map_W)
        // {   
        //     printf("*");
        //     this_map[i][j] = '*';
        //     j++;
        // }
        printf("\n");
        this_map[i][j] = '\0';
        indx++;
        i++;
    }
    //map->map = this_map;

    // int a = 0;
    // printf("----------------------------  MAP  ------------------------------");
    // while (a < map->map_H)
    // {
    //     printf("\n%s", map->map[a]);
    //     a++;
    // }
    // free(this_map); // map->map e atama yaptıktan sonra sil burayı - ya da direkt tüm char atamalarını map->map e yap
    // free(line);
    return 0;
}*/