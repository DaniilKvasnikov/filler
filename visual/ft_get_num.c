/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/29 17:16:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int
	ft_get_num
	(t_player *player)
{
	char		*str;
	int			num;

	num = -1;
	if (get_next_line(0, &str) != 1)
		return (-1);
	if ((ft_strncmp(str, "$$$ exec p", 10) == 0) &&
		(str[10] == '1' || str[10] == '2'))
		num = (str[10] - '0');
	player->name = ft_strdup(str + 14);
	free(str);
	return (player->num = num);
}
