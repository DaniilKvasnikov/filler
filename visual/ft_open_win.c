/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 07:03:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 18:29:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

static int
	skeep_str
	(void)
{
	char	*str;

	if (get_next_line(0, &str) != 1)
		return (0);
	free(str);
	return (1);
}

void		ft_start_game(t_data *data)
{
	data->mydata->run = 1;
	skeep_str();
	skeep_str();
	skeep_str();
	skeep_str();
	skeep_str();
	skeep_str();
	ft_init_player(&data->mydata->player1);
	if ((data->mydata->player1.num = ft_get_num(&data->mydata->player1)) == -1)
		to_exit(&data->mydata->player1);
	skeep_str();
	ft_init_player(&data->mydata->player2);
	if ((data->mydata->player2.num = ft_get_num(&data->mydata->player2)) == -1)
		to_exit(&data->mydata->player2);
}

int				key_press(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	else if (key == 49)
		data->mydata->run = 1;
	return (1);
	free(data);
}

void		ft_open_win(char *str)
{
	t_data	data;

	if (((data.mlx_ptr = mlx_init()) == 0) ||
		((data.mlx_win =
		mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, str)) == NULL) ||
		((data.img = (t_img *)malloc(sizeof(t_img))) == NULL) ||
		((data.mydata = (t_mydata *)malloc(sizeof(t_mydata))) == NULL))
		return ;
	ft_start_game(&data);
	mlx_do_key_autorepeaton(data.mlx_ptr);
	mlx_loop_hook(data.mlx_ptr, ft_draw, &data);
	mlx_hook(data.mlx_win, 2, 1L << 2, key_press, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, ft_close, &data);
	data.img->img_ptr = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
	data.img->data = (int *)mlx_get_data_addr(data.img->img_ptr,
		&data.img->bpp, &data.img->size_l, &data.img->endian);
	mlx_loop(data.mlx_ptr);
}
