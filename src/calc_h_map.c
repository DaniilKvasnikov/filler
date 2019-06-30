/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_h_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 15:10:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

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

void
	calc_h_map_rev
	(t_player *player,
	int *res)
{
	int	i;
	int	j;

	i = player->size[0];
	while (--i >= 0)
	{
		j = player->size[1];
		while (--j >= 0)
		{
			if (player->h[i * player->size[1] + j] <= 0)
			{
				if ((player->h[i * player->size[1] + j] =
					sosed_h(player, i, j)) == 0)
				{
					(*res) = 0;
				}
			}
		}
	}
}

int
	calc_h_map_fun(t_player *player)
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
				if ((player->h[i * player->size[1] + j] =
					sosed_h(player, i, j)) == 0)
					res = 0;
			}
		}
	}
	calc_h_map_rev(player, &res);
	return (res);
}

int
	calc_h_map
	(t_player *player)
{
	while (calc_h_map_fun(player) == 0)
		;
	return (1);
}
