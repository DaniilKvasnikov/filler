/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearwin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 03:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 16:16:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

void			ft_clearwin(t_data *data)
{
	int index;

	if (data->img->size_l <= 100)
		return ;
	index = -1;
	ft_bzero(data->img->data, WIN_W * WIN_H);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img->img_ptr, 0, 0);
}
