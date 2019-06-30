/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 15:12:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

void
	set_map
	(char c,
	int *color,
	char *str,
	t_mydata *data)
{
	data->p1 += (c == 1) + (c == 3);
	data->p2 += (c == 2) + (c == 4);
	if (c == 1)
	{
		*color = 0x008800;
		*str = 'O';
	}
	else if (c == 3)
	{
		*color = 0x00ff00;
		*str = 'o';
	}
	else if (c == 2)
	{
		*color = 0x880000;
		*str = 'X';
	}
	else if (c == 4)
	{
		*color = 0xff0000;
		*str = 'x';
	}
	else if (c == 0)
		*color = 0xffffff;
}
