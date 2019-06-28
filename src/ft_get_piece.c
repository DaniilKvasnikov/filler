/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 15:41:09 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
		if (str[index] == '\0')
		{
			free(str);
			return (0);
		}
		j = 0;
		while (str[index] != '\0')
		{
			if (str[index] != '.' && str[index] != '*')
			{
				free(str);
				return (0);
			}
			if (str[index] == '*')
				player->piece[j + str_num * player->size_piece[1]] = 1;
			else
				player->piece[j + str_num * player->size_piece[1]] = 0;
			index++;
			j++;
		}
		str_num++;
		free(str);
	}
	return (1);
}
