/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 18:37:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

void		ft_draw_map(t_player *player, t_data *data)
{
	int		i;
	int		j;
	char	*str;
	int		color;

	i = 0;
	while (i < player->size[0])
	{
		j = 0;
		while (j < player->size[1])
		{
			color = 0xffffff;
			if (player->map[i * player->size[1] + j] == 1)
				color = 0x00ff00;
			else if (player->map[i * player->size[1] + j] == 2)
				color = 0xff0000;
			else if (player->map[i * player->size[1] + j] == 3)
				color = 0x008800;
			else if (player->map[i * player->size[1] + j] == 4)
				color = 0x880000;
			str = ft_itoa(player->map[i * player->size[1] + j]);
			mlx_string_put(data->mlx_ptr, data->mlx_win,
			i * HOR + 10, j * VER + 10, color, str);
			free(str);
			j++;
		}
		i++;
	}
}

void		ft_draw_piece(t_player *player, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < player->size_piece[0])
	{
		j = 0;
		while (j < player->size_piece[1])
		{
			if (player->piece[i * player->size_piece[1] + j] == 1)
				mlx_string_put(data->mlx_ptr, data->mlx_win,
				i * HOR + WIN_W - (player->size_piece[0] * HOR) - 10, j * VER + 10,
				0xff0000, "*");
			else
				mlx_string_put(data->mlx_ptr, data->mlx_win,
				i * HOR + WIN_W - (player->size_piece[0] * HOR) - 10, j * VER + 10,
				0xffffff, ".");
			j++;
		}
		i++;
	}
}

void
	ft_piece_push
	(t_player *player,
	t_vect_int vect,
	int n)
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
					n;
			j_p++;
		}
		i_p++;
	}
}

int
	ft_get_step
	(t_player *player,
	t_data *data)
{
	char	*str;
	int		i;

	if (get_next_line(0, &str) != 1)
		return (0);
	if ((ft_strncmp(str, "<got (", 6) == 0))
	{
		player->piece_center[0] = ft_atoi(str + 11);
		i = 0;
		while (*(str + 6 + i) != ' ' && *(str + 11 + i + 1) != '\0')
			i++;
		player->piece_center[1] = ft_atoi(str + 11 + i);
		free(str);
		ft_piece_push(&data->mydata->player1, (t_vect_int){player->piece_center[0], player->piece_center[1]},
		3 + (str[6] == 'X'));
		return (1);
	}
	free(str);
	return (0);
}

int			ft_draw(t_data *data)
{
	if (data->mydata->run <= 0)
		return (1);
	data->mydata->run--;
	if (!ft_get_map_size(&data->mydata->player1))
		return (1);
	if (!ft_get_map(&data->mydata->player1))
		return (1);
	if (!get_piece_size(&data->mydata->player1))
		return (1);
	if (!ft_get_piece(&data->mydata->player1))
		return (1);
	if (!ft_get_step(&data->mydata->player1, data))
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	10, WIN_H - 50, 0x00ff00, data->mydata->player1.name);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	10, WIN_H - 30, 0xff0000, data->mydata->player2.name);
	if (data->mydata->player1.map != NULL)
	{
		ft_draw_map(&data->mydata->player1, data);
		ft_draw_piece(&data->mydata->player1, data);
	}
	return (1);
}
