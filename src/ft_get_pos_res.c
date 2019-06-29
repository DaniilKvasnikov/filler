/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 18:07:47 by rrhaenys         ###   ########.fr       */
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
	float	dist;
	int		min;

	i = -1;
	min = 0;
	while (++i < player->size[0])
	{
		j = -1;
		while (++j < player->size[1])
		{
			if (player->map[i * player->size[1] + j] == 2)
			{
				dist = (i - pos.x) * (i - pos.x) + (j - pos.y) * (j - pos.y);
				if (min == 0 || dist < min)
					min = dist;
			}
		}
	}
	return (min);
}

static t_vect_int
	vect_res
	(t_list_filler *list,
	t_player *player)
{
	t_vect_int	res;
	t_vect_int	center;
	t_vect_int	index_v;
	float		min;
	float		index_m;

	res = list->vect;
	center = (t_vect_int){res.x + player->piece_center[0],
							res.y + player->piece_center[1]};
	min = dist_player(player, center);
	while (list != NULL)
	{
		index_v = list->vect;
		center = (t_vect_int){index_v.x + player->piece_center[0],
								index_v.y + player->piece_center[1]};
		index_m = dist_player(player, center);
		if (index_m < min)
		{
			min = index_m;
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
