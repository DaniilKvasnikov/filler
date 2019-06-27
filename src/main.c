#include "main.h"

int
	ft_get_num
	(char *str)
{
	if ((ft_strncmp(str, "exec p", 6) == 0) &&
		(str[6] == '1' || str[6] == '2') &&
		(ft_strcmp(str + 7, " : rrhaenys") == 0))
	{
		return (str[6] - '0');
	}
	return (-1);
}

int
	main
	(int argc, char const *argv[])
{
	char *line;
	t_player player;

	if (argc < 0)
		ft_printf("%s", argv[0]);
	if (argc == 1)
	{
		if (get_next_line(0, &line) == 1)
		{
			player.num = ft_get_num(line);
			ft_printf("num=%d\n", player.num);
			if (player.num == -1)
				return (1);
			free(line);
		}
	}
	return 0;
}
