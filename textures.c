#include "cube3d.h"

// okunan texture'lar ve gloor-ceiling ayarı yapılacak. YAPMADIM HENUZ
// map file map başlangıcına kadar getirildi
int load_textures(int fd, t_game *game)
{
    char *line;
    (void)game;

    line = NULL;
    while (1)
    {
        line = get_next_line(fd); // gnl da malloc kullanıldı - line free lenecek.
        if (!line)
            return 1;
        // burada map 'e kadar okunan texture'lar ve gloor-ceiling ayarı yapılır - şimdilik yapmıyorum
        if (line[0] == 'C') // aynısa 0 döndüğünü varsayıyorum.
        {
            free(line);
            return 0;
        }
        free(line);
    }
    return 1;
}


