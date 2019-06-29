/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 18:22:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

t_vect_int
	ft_get_pos
	(t_player *player)
{
	int				i;
	int				j;
	t_list_filler	*list;
	int				n;

	i = 0;
	list = NULL;
	while (i < player->size[0])
	{
		j = 0;
		while (j < player->size[1])
		{
			if ((n = ft_piece_can_push(player, (t_vect_int){i, j})) == 1)
				list = add_list_filler(list, (t_vect_int){i, j});
			j++;
		}
		i++;
	}
	return (ft_get_pos_res(list, player));
}
