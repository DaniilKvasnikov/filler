/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 14:30:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

static void
	set_map
	(char c,
	int *color,
	char *str,
	t_mydata *data)
{
	if (c == 1)
	{
		*color = 0x008800;
		*str = 'O';
		data->p1++;
	}
	else if (c == 3)
	{
		*color = 0x00ff00;
		*str = 'o';
		data->p1++;
	}
	else if (c == 2)
	{
		*color = 0x880000;
		*str = 'X';
		data->p2++;
	}
	else if (c == 4)
	{
		*color = 0xff0000;
		*str = 'x';
		data->p2++;
	}
	else if (c == 0)
		*color = 0xffffff;
}

void		ft_draw_map(t_player *player, t_data *data)
{
	int		i;
	int		j;
	char	*str;
	int		color;

	data->mydata->p1 = 0;
	data->mydata->p2 = 0;
	i = 0;
	while (i < player->size[0])
	{
		j = 0;
		while (j < player->size[1])
		{
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

void		ft_print_info(t_data *data)
{
	char	*str;

	str = ft_itoa(data->mydata->p1);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 550, 10, 0x00ff00, str);
	free(str);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 500, 10, 0x00ff00, data->mydata->player1.name);
	str = ft_itoa(data->mydata->p2);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 550, 30, 0xff0000, str);
	free(str);
	mlx_string_put(data->mlx_ptr, data->mlx_win,
	WIN_W - 500, 30, 0xff0000, data->mydata->player2.name);
}

int			ft_draw(t_data *data)
{
	if (data->mydata->run > 0)
	{
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
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
	if (data->mydata->player1.map != NULL)
	{
		ft_draw_map(&data->mydata->player1, data);
		ft_draw_piece(&data->mydata->player1, data);
	}
	ft_print_info(data);
	return (1);
}
