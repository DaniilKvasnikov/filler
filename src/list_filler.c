/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 17:53:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

t_list_filler
	*create_list_filler
	(t_vect_int vect)
{
	t_list_filler	*obj;

	obj = (t_list_filler *)malloc(sizeof(t_list_filler));
	if (obj == NULL)
		return (NULL);
	obj->vect = vect;
	obj->next = NULL;
	return (obj);
}

t_list_filler
	*add_list_filler
	(t_list_filler *start,
	t_vect_int vect)
{
	t_list_filler	*obj;
	t_list_filler	*index;

	obj = create_list_filler(vect);
	if (start == NULL)
		return (obj);
	index = start;
	while (index->next != NULL)
		index = index->next;
	index->next = obj;
	return (start);
}

void
	destroy_list_filler
	(t_list_filler *list)
{
	if (list == NULL)
		return ;
	if (list->next != NULL)
		destroy_list_filler(list->next);
	free(list);
}
