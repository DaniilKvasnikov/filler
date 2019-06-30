/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 14:35:08 by rrhaenys         ###   ########.fr       */
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
	{
		player->map[map_n + str_num * player->size[1]] = 0;
		player->h[map_n + str_num * player->size[1]] = 0;
	}
	else if (c == 'x' || c == 'X')
	{
		player->map[map_n + str_num * player->size[1]] = 1 + (player->num != 2);
		player->h[map_n + str_num * player->size[1]] = 1 + (player->num != 2);
	}
	else if (c == 'o' || c == 'O')
	{
		player->map[map_n + str_num * player->size[1]] = 1 + (player->num != 1);
		player->h[map_n + str_num * player->size[1]] = 1 + (player->num != 1);
	}
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
	get_width_h
	(t_player *player,
	int i,
	int j)
{
	if (i < 0 || i >= player->size[0])
		return (0);
	if (j < 0 || j >= player->size[1])
		return (0);
	return (player->h[i * player->size[1] + j]);
}

int
	h_max
	(int s[4])
{
	int res;

	res = -100;
	if (s[0] < 0 && s[0] > res)
		res = s[0];
	if (s[1] < 0 && s[1] > res)
		res = s[1];
	if (s[2] < 0 && s[2] > res)
		res = s[2];
	if (s[3] < 0 && s[3] > res)
		res = s[3];
	return (res);
}

int
	sosed_h
	(t_player *player,
	int i,
	int j)
{
	int s[4];

	s[0] = get_width_h(player, i - 1, j);
	s[1] = get_width_h(player, i + 1, j);
	s[2] = get_width_h(player, i, j - 1);
	s[3] = get_width_h(player, i, j + 1);
	if (s[0] == 2 || s[1] == 2 || s[2] == 2 || s[3] == 2)
		return (-1);
	else if (s[0] <= 0 || s[1] <= 0 || s[2] <= 0 || s[3] <= 0)
		return (h_max(s) - 1);
	else if (s[0] == 1 && s[1] == 1 && s[2] == 1 && s[3] == 1)
		return (1);
	return (0);
}

int
	calc_h_map(t_player *player)
{
	int	i;
	int	j;
	int res;

	i = -1;
	res = 1;
	while (++i < player->size[0])
	{
		j = -1;
		while (++j < player->size[1])
		{
			if (player->h[i * player->size[1] + j] <= 0)
			{
				if ((player->h[i * player->size[1] + j] = sosed_h(player, i, j)) == 0)
				{
					res = 0;
				}
			}
		}
	}
	while (--i >= 0)
	{
		j = player->size[1];
		while (--j >= 0)
		{
			if (player->h[i * player->size[1] + j] <= 0)
			{
				if ((player->h[i * player->size[1] + j] = sosed_h(player, i, j)) == 0)
				{
					res = 0;
				}
			}
		}
	}
	// ft_printf("res=%d\n", res);
	return (res);
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
	// calc_h_map(player);
	while (calc_h_map(player) == 0)
		;
	// ft_print_map(*player);
	return (1);
}
