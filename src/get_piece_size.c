/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 15:41:45 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int
	get_piece_size
	(t_player *player)
{
	char	*str;
	int		i;
	
	if (get_next_line(0, &str) != 1)
		return (0);
	if ((ft_strncmp(str, "Piece ", 6) == 0))
	{
		player->size_piece[0] = ft_atoi(str + 6);
		i = 0;
		while (*(str + 6 + i) != ' ' && *(str + 6 + i + 1) != '\0')
			i++;
		player->size_piece[1] = ft_atoi(str + 6 + i);
		if (player->piece != NULL)
			free(player->piece);
		player->piece =
			(char *)malloc(sizeof(char) *
			(player->size_piece[0] * player->size_piece[1]));
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
