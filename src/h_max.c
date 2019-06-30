/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_max.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 15:10:56 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int
	h_max
	(int s[4])
{
	int res;

	res = -100;
	if (s[0] < 0 && s[0] > res)
		res = s[0];
	if (s[1] < 0 && s[1] > res)
		res = s[1];
	if (s[2] < 0 && s[2] > res)
		res = s[2];
	if (s[3] < 0 && s[3] > res)
		res = s[3];
	return (res);
}