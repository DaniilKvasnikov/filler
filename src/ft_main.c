/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:19:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 16:44:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int
	main
	(void)
{
	t_player	player;
	t_vect_int	vect;

	ft_init_player(&player);
	if ((player.num = ft_get_num()) == -1)
		return (to_exit(&player));
	while (1)
	{
		if (!ft_get_map_size(&player))
			return (to_exit(&player));
		if (!ft_get_map(&player))
			return (to_exit(&player));
		if (!get_piece_size(&player))
			return (to_exit(&player));
		if (!ft_get_piece(&player))
			return (to_exit(&player));
		vect = ft_get_pos(&player);
		ft_printf("%d %d\n", vect.x, vect.y);
	}
	return (0);
}
