#include "main.h"

int
	ft_get_num
	(void)
{
	char	*str;
	int		num;

	num = -1;
	if (get_next_line(0, &str) != 1)
		return (num);
	if ((ft_strncmp(str, "exec p", 6) == 0) &&
		(str[6] == '1' || str[6] == '2') &&
		(ft_strcmp(str + 7, " : rrhaenys") == 0))
		num = (str[6] - '0');
	free(str);
	return (num);
}

int
	main
	(void)
{
	t_player	player;

	player.num = ft_get_num();
	if (player.num == 0)
		ft_printf("num=%d\n", player.num);
	ft_printf("%d %d\n", 0, 0);
	return 0;
}
