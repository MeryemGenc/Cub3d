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
        // burada map 'e kadar okunan texture'lar ve gloor-ceiling ayarı yapılır - şimdilik yapmıyorum
        if (line[0] == 'C')
        {
            free(line);
            return (0);
        }
        free(line);
    }
    return (1);
}


