/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:17:55 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 15:00:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler_vis.h"

int
	main
	(int argc, char **argv)
{
	if (argc == 1)
		ft_open_win(argv[0]);
	return (0);
}
