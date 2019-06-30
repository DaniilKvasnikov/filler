/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 14:44:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void
	ft_set_piece
	(char c,
	t_player *player,
	int str_num,
	int j)
{
	if (c == '*')
		player->piece[j + str_num * player->size_piece[1]] = 1;
	else
		player->piece[j + str_num * player->size_piece[1]] = 0;
}

int
	ft_get_piece
	(t_player *player)
{
	char	*str;
	int		index;
	int		j;
	int		str_num;

	str_num = 0;
	while (str_num < player->size_piece[0])
	{
		if (get_next_line(0, &str) != 1)
			return (0);
		index = 0;
		if (str[index--] == '\0')
			ft_free_str(str);
		j = 0;
		while (str[++index] != '\0')
		{
			if (str[index] != '.' && str[index] != '*')
				ft_free_str(str);
			ft_set_piece(str[index], player, str_num, j++);
		}
		str_num++;
		free(str);
	}
	return (1);
}
