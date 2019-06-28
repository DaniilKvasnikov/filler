/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:41:46 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/28 17:39:28 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "ft_printf.h"

typedef struct	s_player
{
	int			num;
	char		*map;
	char		*piece;
	int			size[2];
	int			size_piece[2];
}				t_player;

typedef struct	s_vect_int
{
	int			x;
	int			y;
}				t_vect_int;

typedef struct	s_list_f
{
	t_vect_int		vect;
	struct s_list_f	*next;
}				t_list_filler;

void			ft_init_player(t_player *player);
int				ft_get_num(void);
int				ft_get_map_size(t_player *player);
int				ft_get_map(t_player *player);
int				get_piece_size(t_player *player);
int				ft_get_piece(t_player *player);
t_vect_int		ft_get_pos(t_player *player);
int				ft_piece_can_push(t_player *player, t_vect_int vect);
t_vect_int		ft_get_pos_res(t_list_filler *list);

int				ft_free_str(char *str);
int				to_exit(t_player *player);

void			ft_print_map(t_player player);
void			ft_print_piece(t_player player);


t_list_filler	*create_list_filler(t_vect_int vect);
t_list_filler	*add_list_filler(t_list_filler *start, t_vect_int vect);

#endif
