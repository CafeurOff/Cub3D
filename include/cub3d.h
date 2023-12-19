/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduthill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:37:38 by lduthill          #+#    #+#             */
/*   Updated: 2023/12/19 03:11:27 by lduthill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}				t_vars;


/* main.c */
void	ft_init_mlx(t_vars data);

/* check.c */
int	ft_check_args(int ac, char **av);
int	check_if_cube(char *str);

#endif
