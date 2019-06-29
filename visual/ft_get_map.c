/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 16:12:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int
	skeep_str
	(void)
{
	char	*str;

	if (get_next_line(0, &str) != 1)
		return (0);
	free(str);
	return (1);
}

static void
	ft_set_map
	(char c,
	t_player *player,
	int str_num,
	int map_n)
{
	if (c == '.')
		player->map[map_n + str_num * player->size[1]] = 0;
	else if (c == 'x' || c == 'X')
		player->map[map_n + str_num * player->size[1]] = 1 + (player->num != 2);
	else if (c == 'o' || c == 'O')
		player->map[map_n + str_num * player->size[1]] = 1 + (player->num != 1);
}

static int
	cor_input
	(char c)
{
	return ((c == '.' || c == 'x' || c == 'X' || c == 'o' || c == 'O'));
}

static int
	get_index
	(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0' && str[index] != ' ')
		index++;
	return (index);
}

int
	ft_get_map
	(t_player *player)
{
	char	*str;
	int		index;
	int		j;
	int		str_num;

	if (!skeep_str())
		return (0);
	str_num = -1;
	while (++str_num < player->size[0])
	{
		if (get_next_line(0, &str) != 1)
			return (0);
		index = get_index(str);
		if (str[index] == '\0' || str[index + 1] == '\0')
			return (ft_free_str(str));
		j = -1;
		while (str[++index] != '\0')
		{
			if (!cor_input(str[index]))
				return (ft_free_str(str));
			ft_set_map(str[index], player, str_num, ++j);
		}
		free(str);
	}
	return (1);
}
