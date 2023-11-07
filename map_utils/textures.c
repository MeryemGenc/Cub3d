#include "../cube3d.h"

// okunan texture'lar ve gloor-ceiling ayarı yapılacak. YAPMADIM HENUZ
// map file map başlangıcına kadar getirildi
int load_textures(int fd, t_map *map)
{
    char *line;

    (void)map;
    line = NULL;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            return (1);
        if (line[0] == 'C')
        {
            free(line);
            return (0);
        }
        free(line);
    }
    return (1);
}

int init_texture(char *line, t_map *map) // bu nasıl isim - ne alaka
{
    int i;

    i = -1;
    while (line[++i])
    {
        if (ft_strchr("NSEW", line[i]))
        {
            map->player_start_indx.x = i;
            map->player_start = line[i];
            return 0;
        }
    }
    return 1;
}


