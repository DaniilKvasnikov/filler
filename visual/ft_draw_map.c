/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 15:13:17 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

void
	ft_draw_elem_map
	(t_player *player,
	t_data *data,
	int i,
	int j)
{
	char	*str;
	int		color;

	str = ft_strdup(".");
	set_map(player->map[i * player->size[1] + j], &color, str, data->mydata);
	if (data->mydata->status == 1)
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		i * HOR + 7, j * VER + 7, color, str);
	else
	{
		if (data->mydata->status == 2)
		{
			free(str);
			str = ft_itoa(player->h[i * player->size[1] + j]);
		}
		mlx_string_put(data->mlx_ptr, data->mlx_win,
		i * HOR_DOP + 7, j * VER + 7, color, str);
	}
	free(str);
}

void
	ft_draw_map
	(t_player *player,
	t_data *data)
{
	int		i;
	int		j;

	data->mydata->p1 = 0;
	data->mydata->p2 = 0;
	i = 0;
	while (i < player->size[0])
	{
		j = 0;
		while (j < player->size[1])
		{
			ft_draw_elem_map(player, data, i, j);
			j++;
		}
		i++;
	}
}
