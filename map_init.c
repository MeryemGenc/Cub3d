#include "cube3d.h"

// map i oku ve struct a at
// struct üzerinden kontrolleri yap
    // ***********.cub uzantısı 
    // ***********map ulaşılabilir mi
    // map içindeki .xpm dosya yolları doğru mu
    // map içindeki .xpm dosyalarını 1 struct içerisine at-depola
    // map duvarlarla çevrili mi?
    // map içindeki bilgiler doğru mu?
// map'i direkt game->map structına atamalı mıyım? önce kontrol sonra atamamı olsun? ne verim abime.

char *read_map_line(int fd, t_game *game)
{
    char *line;
    char *tmp_map;

    tmp_map = malloc(1);
    game->map->map_X = 0;
    game->map->map_Y = 1;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        game->map->map_Y++;
        tmp_map = ft_gnl_strjoin(tmp_map, line);
        if ((int)ft_strlen(line) > game->map->map_X)
            game->map->map_X = (int)ft_strlen(line); // 35 okudu (\n+NULL)
        if (line) 
            free(line);
    }
    // if (line) 
    //     free(line);
    return tmp_map;
}

int create_map(int fd,t_game *game)
{
    char *tmp_map;

    get_next_line(fd); // map ile texture dostası arasındaki new line'ları kontrol etmeli miyiz?
    tmp_map = read_map_line(fd, game);
    game->map->map = ft_split(tmp_map, '\n'); // sonunda sadece 1 adet \n var
    free(tmp_map); printf("1");
    map_parsing(game); // hata olursa 1 değişkene al bunu.
    // game-<map e malloc ile yer ayırıp ataması yapılacak

    return 0;
    // satır okuycam  +  okunan satırları **map e atcam
}

int read_map(char *map_name, t_game *game)
{
    int fd;

    fd = open(map_name, O_RDONLY);
    if (fd < 0)
        return print_err("Map file can not open.") - 49; // bunun NULL döndürmesi gerek.NULL döndürüyor mu? KONTROL ET
    load_textures(fd, game); // map'in üst kısmının yanlış verilmeyeceğini varsayıp kontrol etmedim.
    create_map(fd, game);
    close(fd);
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
    game->map = malloc(sizeof(t_map));
    if (read_map(map_name, game))
        return 1;

    return 0;
}
