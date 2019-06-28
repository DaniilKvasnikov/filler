/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 13:52:35 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int
	ft_get_map_size
	(t_player *player)
{
	char	*str;
	int		i;
	
	if (get_next_line(0, &str) != 1)
		return (0);
	if ((ft_strncmp(str, "Plateau ", 8) == 0))
	{
		player->size[0] = ft_atoi(str + 8);
		i = 0;
		while (*(str + 8 + i) != ' ' && *(str + 8 + i + 1) != '\0')
			i++;
		player->size[1] = ft_atoi(str + 8 + i);
		player->map =
			(char *)malloc(sizeof(char) * (player->size[0] * player->size[1]));
		return (1);
	}
	return (0);
}
