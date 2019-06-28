/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 13:50:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 13:51:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "ft_printf.h"

typedef struct	s_player
{
    int         num;
    char        *map;
    char        *piece;
    int         size[2];
    int         size_piece[2];
}				t_player;

typedef struct	s_vect_int
{
    int         x;
    int         y;
}				t_vect_int;

void            ft_init_player(t_player *player);
int             ft_get_num(void);
int             ft_get_map_size(t_player *player);
int             ft_get_map(t_player *player);
int             get_piece_size(t_player *player);
int             ft_get_piece(t_player *player);

void            ft_print_map(t_player player);
void            ft_print_piece(t_player player);

#endif
