#include "main.h"

int
	ft_get_num
	(void)
{
	char	*str;
	int		num;

	num = -1;
	if (get_next_line(0, &str) != 1)
		return (-1);
	if ((ft_strncmp(str, "$$$ exec p", 10) == 0) &&
		(str[10] == '1' || str[10] == '2'))
			num = (str[10] - '0');
	free(str);
	return (num);
}

int
	ft_get_map
	(t_player *player)
{
	char	*str;
	int		i;
	
	if (get_next_line(0, &str) != 1)
		return (0);
	if ((ft_strncmp(str, "Plateau ", 8) == 0))
	{
		player->size[0] = ft_atoi(str + 8);
		i = 0;
		while (*(str + 8 + i) != ' ' && *(str + 8 + i + 1) != '\0')
			i++;
		player->size[1] = ft_atoi(str + 8 + i);
		return (1);
	}
	return (0);
}

int
	main
	(void)
{
	t_player	player;

	if ((player.num = ft_get_num()) == -1)
		return (0);
	if (!ft_get_map(&player))
		return (0);
	ft_printf("%d %d\n", player.size[0], player.size[1]);
	return 0;
}
