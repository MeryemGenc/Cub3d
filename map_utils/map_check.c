#include "../cube3d.h"

int map_check(t_map *map)
{
    int i;
    int j;
    int flag;
                // 1 space space space -> space_flag = 1
                // 1 space space space 1 space space space -> space_flag = 1
    i = -1;     // space space space 1 -> space_flag = 0
    while (map->map[++i] && i < map->map_H) // space öncesi ve sonrası da 1 olması - NULL öncesi 1 olmalı
    {
        flag = 0;
        j = -1;
        printf("\n%d. satir uzunluk: %d", i, (int)ft_strlen(map->map[i])); // deneme - 0. satır: 34
        while (map->map[i][++j] && j < (int)ft_strlen(map->map[i])-1)
        {
            if (flag == 0 && map->map[i][j] == '1') // flag 0 iken duvar
                flag = 1;
            if (flag == 0 && ft_strchr("NSEW0", map->map[i][j])) // flag 0 iken karakter||yüzey
                return (print_err("1Map must be surround by walls."));
            if (!map->map[i][j + 1] && map->map[i][j] != '1' && flag)// duvar kapanmadan bitiyorsa map
            {
                printf("sssssssssssssssssssssssssss");
                // printf("s: %s", map->map[i]);
                return (print_err("2Map must be surround by walls."));
            }
			if (flag == 1 && map->map[i][j] == ' ')
			{
                if (ft_strchr("NSEW0", map->map[i][j - 1])) // duvardan sonra space varsa flag = 0
                    return (print_err("3Map must be surround by walls."));
				flag = 0;
			}
        }
    }
    return (0);
}

// XOR: farklı bitler için:1 - aynı bitler için: 0
// hata: return 0
/*
static int	horizontalcheck(char **map, int i, int j, int flag)
{
	while (map[++i])
	{
		flag = 0;
		j = -1;
		while (map[i][++j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1; // XOR operatörü -> şov. -> zaten flag 0 ise giriyo. Git direkt 1 yap işte - neyin peşindesin.
			if (flag == 0 && ft_strchr("NSEW0", map[i][j])) // duvar olmadan karakter ya da zemin var demek
				return (0);
			if (flag == 1 && map[i][j] == ' ') // "110001111N" durumunu nerede kontrol ediyoruz? (en sonlara space atamadık ki.)
			{
				if (map[i][j - 1] && ft_strchr("0NSEW", map[i][j - 1])) // ' ''ten önce karakter ya da zemin varsa-neden direkt map[i][j - 1]==1 mi diye bakmıyor? DENE
					return (0);
				flag ^= 1;// flag = 0 ->  duvardan sonra space varsa
			}
		}
	}
	return (1); 
}

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
