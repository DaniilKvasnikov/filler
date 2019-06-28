/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 14:58:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int
	ft_get_map
	(t_player *player)
{
	char	*str;
	int		index;
	int		j;
	int		str_num;

	if (get_next_line(0, &str) != 1)
		return (0);
	free(str);
	str_num = 0;
	while (str_num < player->size[0])
	{
		if (get_next_line(0, &str) != 1)
			return (0);
		index = 0;
		while (str[index] != '\0' && str[index] != ' ')
			index++;
		if (str[index] == '\0' || str[index + 1] == '\0')
			return (0);
		index++;
		j = -1;
		while (str[index] != '\0')
		{
			++j;
			if (!(str[index] == '.' || str[index] == 'x' || str[index] == 'X' ||
			str[index] == 'o' || str[index] == 'O'))
				return (0);
			if (str[index] != '.')
			{
				if (str[index] == 'x' || str[index] == 'X')
					player->map[j + str_num * player->size[1]] = 1 + (player->num != 2);
				else if (str[index] == 'o' || str[index] == 'O')
					player->map[j + str_num * player->size[1]] = 1 + (player->num != 1);
			}
			else
				player->map[j + str_num * player->size[1]] = 0;
			index++;
		}
		str_num++;
	}
	return (1);
}
