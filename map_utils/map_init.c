#include "../cube3d.h"

// struct üzerinden kontrolleri yap
    // ***********.cub uzantısı 
    // ***********map ulaşılabilir mi
    // map içindeki .xpm dosya yolları doğru mu
    // map içindeki .xpm dosyalarını 1 struct içerisine at-depola
    // map duvarlarla çevrili mi?
    // map içindeki bilgiler doğru mu?
// map'i direkt game->map structına atamalı mıyım? önce kontrol sonra atamamı olsun? ne verim abime.


int print_map(t_map *map) // sil ilerde
{
    int i = 0;
    while (map->map[i])
    {
        printf("\n%s", map->map[i]);
        i++;
    }
    return (0);
}

char *create_map(int fd, t_map *map)
{
    char *line;
    char *tmp_map;
    int counter;

    line = 0;       // sorun olmayacaksa bunları sil - DENE
    tmp_map = 0;    // sorun olmayacaksa bunları sil - DENE
    counter = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (!init_texture(line, map))
            map->player_start_indx.y = counter;
        if (map->map_W < (int)ft_strlen(line))
            map->map_W = (int)ft_strlen(line);
        tmp_map = ft_gnl_strjoin(tmp_map, line);
        free(line);
        counter++;
    }
    map->map_W = counter;
    return (tmp_map);
}

int read_map(char *map_name, t_map *map)
{
    int fd;
    char *line;

    fd = open(map_name, O_RDONLY);
    if (fd < 0)
        return (print_err("Map file can not open."));
    load_textures(fd, map);
    get_next_line(fd); // direkt free(get_next_line(fd)); oluyor mu? dene.
    line = create_map(fd, map);
    printf("\nmaph: %d mapw: %d\n", map->map_H, map->map_W);
    map->map = ft_split(line, '\n');

    free(line);
    close(fd);
    return (0);
}

int check_map_extension(char *map_name)
{
    int len;

    len = ft_strlen(map_name) - 1;
    if (map_name[len] == 'b' && map_name[--len] == 'u' && map_name[--len] == 'c' && map_name[--len] == '.' && len > 4)
        return (0);
    return (1);
}

int map_init(char *map_name, t_map *map)
{
    if (check_map_extension(map_name))
        return (print_err("Wrong map format."));
    if (read_map(map_name, map))
        return (1);
    if (map_check(map))
        return (1);
    return (0);
}
