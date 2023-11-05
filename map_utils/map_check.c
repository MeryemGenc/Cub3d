#include "../cube3d.h"

int map_check(t_map *map)
{
    int i;
    int j;
    int flag;

    i = -1;
    while (map->map[++i] && i < map->map_H)
    {
        flag = 0;
        j = -1;
        while (map->map[i][++j] && j < (int)ft_strlen(map->map[i])-1)
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

// Hata: 0 - Başarı: 1
// space ten sonra char ya da zemin varsa: space tekyen flag=0 yaptığımız için HATA verir. 
// int	mapcheck(char **map)
// {
// 	if (!horizontalcheck(map, -1, -1, 0))
// 		return (0);
// 	if (!verticalcheck(map, -1, -1, 0))
// 		return (0);
// 	return (1);
// }
