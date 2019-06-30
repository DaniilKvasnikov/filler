/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 14:47:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void
	ft_print_map
	(t_player player)
{
	int	i;
	int	j;

	j = 0;
	ft_printf("  ");
	while (j < player.size[1])
	{
		ft_printf("%3d ", j % 10);
		j++;
	}
	ft_printf("\n");
	i = 0;
	while (i < player.size[0])
	{
		ft_printf("%3d ", i % 10);
		j = 0;
		while (j < player.size[1])
		{
			ft_printf("%3d ", -player.h[i * player.size[1] + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void
	ft_print_piece
	(t_player player)
{
	int	i;
	int	j;

	i = 0;
	while (i < player.size_piece[0])
	{
		j = 0;
		while (j < player.size_piece[1])
		{
			ft_printf("%d ", player.piece[i * player.size_piece[1] + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
