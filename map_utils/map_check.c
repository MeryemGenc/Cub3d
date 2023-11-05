#include "../cube3d.h" // cube değil cub3d.h olacak - DEĞİŞTİR

int check_horizontal(t_map *map)
{
    int i;
    int j;
    int flag;

    i = -1;
    while (map->map[++i] && i < map->map_H)
    {
        flag = 0;
        j = -1;
        while (map->map[i][++j] && j < (int)ft_strlen(map->map[i]) - 1)
        {
            if (flag == 0 && map->map[i][j] == '1')
                flag = 1;
            if (flag == 0 && ft_strchr("NSEW0", map->map[i][j]))
                return (print_err("1Map must be surround by walls."));
            if (!map->map[i][j + 1] && map->map[i][j] != '1')
                return (print_err("2Map must be surround by walls."));
			if (flag == 1 && map->map[i][j] == ' ')
			{
                if (ft_strchr("NSEW0", map->map[i][j - 1]))
                    return (print_err("3Map must be surround by walls."));
				flag = 0;
			}
        }
    }
    return (0);
}

    //         1111111111111111111111111
    //              1000000000110000000000001
    //         1011000001110000000000001

int check_vertical(t_map *map) // napacaz şimdi ?
{
    int i;
    int j;
    int flag;

    j = -1;
    while (map->map[++j] && j < map->map_W - 1) // sütun
    {
        flag = 0;
        i = -1;
        while ( ++i < map->map_H - 1) // satır
        {
            if (!map->map[i][j] || map->map[i][j] == ' ')
            {
                if (map->map[i - 1][j] && ft_strchr("NSEW0", map->map[i - 1][j]))
                    return (print_err("1Map must be surround by walls."));
                if (map->map[i + 1][j] && ft_strchr("NSEW0", map->map[i + 1][j]))
                    return (print_err("2Map must be surround by walls."));
                flag = 0;
            }
            if (!flag && map->map[i][j] && ft_strchr("NSEW0", map->map[i][j])) // ilk sütun
                return (print_err("3Map must be surround by walls."));
            if (map->map[i][j] && map->map[i][j] == '1')
                flag = 1;
        }
    }
    return (0);
}

int map_check(t_map *map)
{
    if (check_horizontal(map) || check_vertical(map))
        return (1);
    return (0);
}
/*
static int	verticalcheck(char **map, int i, int j, int flag)
{
	while (map[0][++j])
	{
		flag = 0;
		i = 0;
		while (map[i] && map[i][j])
		{
			if (flag == 0 && map[i][j] == '1') // duvar görünce flag == 0 ise =1 yap - DENE
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
			{
				if (map[i - 1] && map[i - 1][j]
						&& ft_strchr("0NSEW", map[i - 1][j]))
					return (0);
				flag ^= 1;
			}
			if (!map[i + 1] && ft_strchr("NSEW0", map[i][j]))  // bu kontrolü horizontalcheck te de yapıp - DENE
			// bu hangi durum için geçerli -> yani diğer if lerin yakalamadığı - bunun yakaladığı hangi durum var? -> 11110111 1110101 101111010001N (vertical düşün)
				return (0);
			i++;
		}
	}
	return (1);
}*/
