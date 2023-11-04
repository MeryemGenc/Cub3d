#include "cube3d.h"

// map i oku ve struct a at
// struct üzerinden kontrolleri yap
    // ***********.cub uzantısı 
    // map ulaşılabilir mi
    // map içindeki .xpm dosya yolları doğru mu
    // map içindeki .xpm dosyalarını 1 struct içerisine at-depola
    // map duvarlarla çevrili mi?
    // map içindeki bilgiler doğru mu?
// map'i direkt game->map structına atamalı mıyım? önce kontrol sonra atamamı olsun? ne verim abime.

int read_map_line(int fd, char *map, t_game *game)
{
    char *line; 
    
    game->map.map_X = 0;
    game->map.map_Y = 0;
    while (1)
    {
        if (line) 
            free(line);
        line = get_next_line(fd);
        if (!line || line[0] == '\n')
            break;
        // if (line[0] == '\n')
        //     break;
        game->map.map_Y++;
        map = ft_gnl_strjoin(map, line);
        if (ft_strlen(line) > game->map.map_X)
            game->map.map_X = ft_strlen(line);
    }
    if (line) 
        free(line);
    return 0;
}

int create_map(int fd,t_game *game)
{
    char *line; 
    char *map;

    while (1)
    {
        line = get_next_line(fd);
        if (!line || !strncmp(line, "\n", 1))
            break;
        free(line);
    }
    read_map_line(fd, map, game); // map i free le - fd yi kapa
    map_parsing(game, map);
    // game-<map e malloc ile yer ayırıp ataması yapılacak

    
    // satır okuycam  +  okunan satırları **map e atcam
}

int read_map(char *map_name, t_game *game)
{
    char **map;
    int i;
    int fd;

    fd = open(map_name, O_RDONLY);
    if (fd < 0)
        return print_err("Map file can not open.") - 49; // bunun NULL döndürmesi gerek.NULL döndürüyor mu? KONTROL ET
    load_textures(fd, game); // map'in üst kısmının yanlış verilmeyeceğini varsayıp kontrol etmedim.
    create_map(fd, game);

    return 0; // başarı durumu
}

int check_map_extension(char *map_name)
{
    int len;

    len = ft_strlen(map_name) - 1;
    if (map_name[len] == 'b' && map_name[--len] == 'u' && map_name[--len] == 'c' && map_name[--len] == '.' && len > 4)
        return 0;
    return print_err("Wrong map extension.");
}

int map_init(char *map_name, t_game *game)
{
    if (check_map_extension(map_name))
        return 1;
    if (read_map(map_name, game))
        return 1;

    return 0;
}
