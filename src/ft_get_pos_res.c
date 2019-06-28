/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pos_res.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 17:52:56 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static t_vect_int
	vect_res
	(t_list_filler *list)
{
	t_vect_int	res;

	res = (list->vect);
	return (res);
}

t_vect_int
	ft_get_pos_res
	(t_list_filler *list)
{
	t_vect_int	res;

	res = (t_vect_int){0, 0};
	if (list != NULL)
		res = vect_res(list);
	destroy_list_filler(list);
	return (res);
}
