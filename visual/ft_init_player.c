/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 15:59:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void
	ft_init_player
	(t_player *player)
{
	player->num = 0;
	player->map = 0;
	player->piece = 0;
	player->size[0] = 0;
	player->size[1] = 0;
	player->piece_center[0] = 0;
	player->piece_center[1] = 0;
	player->piece_count = 0;
}
