#include "../cube3d.h"

// map i oku ve struct a at
// struct üzerinden kontrolleri yap
    // ***********.cub uzantısı 
    // ***********map ulaşılabilir mi
    // map içindeki .xpm dosya yolları doğru mu
    // map içindeki .xpm dosyalarını 1 struct içerisine at-depola
    // map duvarlarla çevrili mi?
    // map içindeki bilgiler doğru mu?
// map'i direkt game->map structına atamalı mıyım? önce kontrol sonra atamamı olsun? ne verim abime.

/*
char *read_map_line(int fd, t_map *map)
{
    char *line;
    char *tmp_map;

    line = 0;
    tmp_map = 0;
    // game->map->map_X = 0;
    // // game->map->map_Y = 1; printf("\n100");
    // while (1)
    // {
    //     if (line)
    //         free(line);
    //     line = get_next_line(fd);
    //     if (ft_strncmp(line, "\n", 1))
    //         break;
    // }
    while (1)
    {
        tmp_map = ft_gnl_strjoin(tmp_map, line);
        // if ((int)ft_strlen(line) > game->map->map_X)
        //     game->map->map_X = (int)ft_strlen(line);
        free(line);
        line = get_next_line(fd);
        if (!line)
            break;
        //game->map->map_Y++;
    }
    printf("aaa: %s", tmp_map);
    return tmp_map;
}*/

char *create_map(int fd, t_map *map)
{
    char *line;
    char *tmp_map;

    line = 0;       // sorun olmayacaksa bunları sil - DENE
    tmp_map = 0;    // sorun olmayacaksa bunları sil - DENE
    map->map_H = 0;
    map->map_W = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (line[0] == '\n')
        {
            free(line);
            break;
        }
        if (map->map_W < (int)ft_strlen(line))
            map->map_W = (int)ft_strlen(line);
        tmp_map = ft_gnl_strjoin(tmp_map, line);
        free(line);
        map->map_H++;
    }
    tmp_map = ft_gnl_strjoin(tmp_map, "\n");
    tmp_map = ft_gnl_strjoin(tmp_map, "\0");
    printf("createmap: %s", tmp_map);


    // map ile texture dostası arasındaki new line'ları kontrol etmeli miyiz?
    //tmp_map = read_map_line(fd, game);
    //read_map_line(fd, game);
    //printf("bbb");
    //game->map->map = ft_split(tmp_map, '\n'); // sonunda sadece 1 adet \n var
    //if (!game->map->map || !game->map->map[0])
    //map_parsing(game); // hata olursa 1 değişkene al bunu.
    // game-<map e malloc ile yer ayırıp ataması yapılacak

    // free(tmp_map);
    return tmp_map;
    // satır okuycam  +  okunan satırları **map e atcam
}

int read_map(char *map_name, t_map *map)
{
    int fd;
    char *line;

    fd = open(map_name, O_RDONLY);
    if (fd < 0)
        return print_err("Map file can not open.");
    load_textures(fd, map); // map'in üst kısmının yanlış verilmeyeceğini varsayıp kontrol etmedim.
    line = get_next_line(fd); // direkt free(get_next_line(fd)); oluyor mu? dene.
    free(line);
    line = create_map(fd, map);
    printf("\nmaph: %d mapw: %d\n", map->map_H, map->map_W);
    printf("\nline: %s", line); // line ınson satırında 1 sıkıntı var
    int a = 0;
    while (a++ < 20)
    {
    printf("*");
    }
    
    map_parsing(map, line); // map_parsing(map, create_map(fd, map)); - DENE
    close(fd);
    return 0;
}

int check_map_extension(char *map_name)
{
    int len;

    len = ft_strlen(map_name) - 1;
    if (map_name[len] == 'b' && map_name[--len] == 'u' && map_name[--len] == 'c' && map_name[--len] == '.' && len > 4)
        return 0;
    return 1;
}

int map_init(char *map_name, t_map *map)
{
    if (check_map_extension(map_name))
        return print_err("Wrong map format.");
    if (read_map(map_name, map))
        return 1;

    return 0;
}
