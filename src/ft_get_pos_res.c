/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 14:51:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int
	dist_player
	(t_player *player,
	t_vect_int pos)
{
	int		i;
	int		j;
	int		res;
	int		x;
	int		y;

	i = -1;
	res = 0;
	while (++i < player->size_piece[0])
	{
		j = -1;
		while (++j < player->size_piece[1])
		{
			if (player->piece[i * player->size[1] + j] == 1)
			{
				x = i + pos.x;
				y = j + pos.y;
				if (player->map[(x) * player->size[1] + (y)] == 0)
					res += player->h[(x) * player->size[1] + (y)];
			}
		}
	}
	return (res);
}

static t_vect_int
	vect_res
	(t_list_filler *list,
	t_player *player)
{
	t_vect_int	res;
	t_vect_int	index_v;
	int			max;
	int			index_m;

	res = list->vect;
	max = dist_player(player, res);
	while (list != NULL)
	{
		index_v = list->vect;
		index_m = dist_player(player, index_v);
		if ((index_m > max && index_m < 0) || max >= 0)
		{
			max = index_m;
			res = list->vect;
		}
		list = list->next;
	}
	return (res);
}

t_vect_int
	ft_get_pos_res
	(t_list_filler *list,
	t_player *player)
{
	t_vect_int	res;

	res = (t_vect_int){0, 0};
	if (list != NULL)
		res = vect_res(list, player);
	destroy_list_filler(list);
	return (res);
}
