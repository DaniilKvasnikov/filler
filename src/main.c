/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 13:50:25 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int
	ft_piece_can_push
	(t_player *player,
	t_vect_int vect)
{
	int i_p;
	int j_p;
	int	trig;

	if ((vect.x + player->size_piece[0]) > player->size[0])
		return (0);
	if ((vect.y + player->size_piece[1]) > player->size[1])
		return (0);
	trig = 0;
	i_p = 0;
	while (i_p < player->size_piece[0])
	{
		j_p = 0;
		while (j_p < player->size_piece[1])
		{
			if (player->piece[i_p * player->size_piece[1] + j_p])
			{
				if (player->map[(vect.x + i_p) * player->size[1] + (vect.y + j_p)] == 1)
					trig++;
				else if (player->map[(vect.x + i_p) * player->size[1] + (vect.y + j_p)] == 2)
					return (0);
			}
			j_p++;
		}
		i_p++;
	}
	return (trig == 1);
}

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
				player->map[(vect.x + i_p) * player->size[1] + (vect.y + j_p)] = 1;
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
	return ((t_vect_int){1, 1});
}

int
	main
	(void)
{
	t_player	player;
	t_vect_int	vect;

	ft_init_player(&player);
	if ((player.num = ft_get_num()) == -1)
		return (0);
	if (!ft_get_map_size(&player))
		return (0);
	if (!ft_get_map(&player))
		return (0);
	if (!get_piece_size(&player))
		return (0);
	if (!ft_get_piece(&player))
		return (0);
	vect = ft_get_pos(&player);
	// ft_print_map(player);
	// ft_print_piece(player);
	ft_printf("%d %d\n", vect.x, vect.y);
	return 0;
}
