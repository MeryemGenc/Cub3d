#include "cube3d.h"

// map i oku ve struct a at
// struct üzerinden kontrolleri yap
    // ***********.cub uzantısı 
    // map ulaşılabilir mi
    // map içindeki .xpm dosya yolları doğru mu
    // map içindeki .xpm dosyalarını 1 struct içerisine at-depola
    // map duvarlarla çevrili mi?
    // map içindeki bilgiler doğru mu?

int map_init(char *map_name)
{
    if (check_map_extension(map_name))
        return 1;
    return 0;
}

int check_map_extension(char *map_name)
{
    int len;

    len = ft_strlen(map_name) - 1;
    if (map_name[len] == 'b' && map_name[--len] == 'u' && map_name[--len] == 'c' && map_name[--len] == '.')
        return 0;
    return print_err("Wrong map extension.");
}
