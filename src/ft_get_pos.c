/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 16:44:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void
	ft_piece_push
	(t_player *player,
	t_vect_int vect)
{
	int i_p;
	int j_p;

	i_p = 0;
	while (i_p < player->size_piece[0])
	{
		j_p = 0;
		while (j_p < player->size_piece[1])
		{
			if (player->piece[i_p * player->size_piece[1] + j_p])
				player->map[(vect.x + i_p) * player->size[1] + (vect.y + j_p)] =
					1;
			j_p++;
		}
		i_p++;
	}
}

t_vect_int
	ft_get_pos
	(t_player *player)
{
	int i;
	int j;

	i = 0;
	while (i < player->size[0])
	{
		j = 0;
		while (j < player->size[1])
		{
			if (ft_piece_can_push(player, (t_vect_int){i, j}))
			{
				ft_piece_push(player, (t_vect_int){i, j});
				return ((t_vect_int){i, j});
			}
			j++;
		}
		i++;
	}
	return ((t_vect_int){0, 0});
}
