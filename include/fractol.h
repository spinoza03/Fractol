/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:38:05 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/18 16:52:39 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "../mlx/mlx.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_fractal;
// Function prototypes
void	ft_putstr_fd(char *s, int fd);
void	init_mlx(t_fractal *fractal);
void	draw_fractal(t_fractal *fractal);
int	ft_strcmp(char *s1, char *s2);
int	pars_args(char *s1, char *s2);
double	ft_atof(const char *str, int *error);
#endif