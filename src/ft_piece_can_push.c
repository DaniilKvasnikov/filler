/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece_can_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 16:44:03 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int
	on_map
	(t_player *player,
	t_vect_int vect)
{
	if (((vect.x + player->size_piece[0]) > player->size[0]))
		return (0);
	if ((vect.y + player->size_piece[1]) > player->size[1])
		return (0);
	return (1);
}

static int
	pice_main
	(t_player *player,
	t_vect_int vect,
	int i_p,
	int j_p)
{
	if (player->piece[i_p * player->size_piece[1] + j_p])
	{
		if (player->map[(vect.x + i_p) * player->size[1] + (vect.y + j_p)] == 1)
			return (1);
		else if (
			player->map[(vect.x + i_p) * player->size[1] + (vect.y + j_p)] == 2)
			return (-1);
	}
	return (0);
}

int
	ft_piece_can_push
	(t_player *player,
	t_vect_int vect)
{
	int i_p;
	int j_p;
	int	trig;
	int	n;

	if (!on_map(player, vect))
		return (0);
	trig = 0;
	i_p = -1;
	while (++i_p < player->size_piece[0])
	{
		j_p = -1;
		while (++j_p < player->size_piece[1])
		{
			n = pice_main(player, vect, i_p, j_p);
			if (n < 0)
				return (0);
			trig += n;
		}
	}
	return (trig == 1);
}
