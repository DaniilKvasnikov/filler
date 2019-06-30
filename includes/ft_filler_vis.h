/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_vis.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:41:46 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/06/30 14:30:09 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_FILLER_VIS_H
# define FT_FILLER_VIS_H

# include "ft_filler.h"
# include <mlx.h>
# include <math.h>

# define WIN_H 1300
# define WIN_W (WIN_H * 16 / 9)
# define WIN_S (WIN_W * WIN_H)
# define HOR 12
# define HOR_DOP 40
# define VER 12

typedef struct	s_mydata
{
	t_player	player1;
	t_player	player2;
	int			run;
	int			p1;
	int			p2;
	int			status;
}				t_mydata;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*img;
	t_mydata	*mydata;
}				t_data;

void		ft_open_win(char *str);
int			ft_draw(t_data *data);
int			ft_close(t_data *data);
void		ft_clearwin(t_data *data);

#endif
