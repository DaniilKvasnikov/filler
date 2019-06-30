/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 13:10:42 by rrhaenys         ###   ########.fr       */
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

	i = -1;
	res = 0;
	while (++i < player->size_piece[0])
	{
		j = -1;
		while (++j < player->size_piece[1])
		{
			if (player->piece[i * player->size[1] + j] == 1)
			{
				if (player->map[(i + pos.x) * player->size[1] + (j + pos.y)] == 0)
				{
					res += player->h[(i + pos.x) * player->size[1] + (j + pos.y)];
				}
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
		// ft_printf("%d %d = %d\n", index_v.x, index_v.y, index_m);
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
