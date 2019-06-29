/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 16:04:04 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

int
	to_exit
	(t_player *player)
{
	if (player->map != NULL)
		free(player->map);
	if (player->piece != NULL)
		free(player->piece);
	ft_close(0);
	return (0);
}
