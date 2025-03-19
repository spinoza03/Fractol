/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:38:05 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/19 00:21:39 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
#include "../mlx/mlx.h"

# define HEIGHT	900
# define WIDTH	900
# define MAX_ITER 100
# define BLACK 0x000000

typedef struct s_nbr_cmplx
{
	double	real;
	double	img;
}	t_nbr_cmplx;

typedef struct s_img_data
{
	void	*img_ptr;
	char	*pix_data;
	int		bit_pix;
	int		line_len;
	int		endian;
	int		color;
}	t_img_data;

typedef struct s_fractol
{
	double		zoom;
	void		*mlx;
	void		*mlx_init_ptr;
	void		*mlx_win_ptr;
	char		*title;
	int			iter_n;
	double		x_start;
	double		x_end;
	double		y_start;
	double		y_end;
	t_img_data	img;
	t_nbr_cmplx	z;
	t_nbr_cmplx	c_julia;
}	t_fractol;

/* Utility Functions */
void		ft_put_err(char *str, int fd);
double		ft_atod(char *str);
int			ft_isspace(char *str);
int			ft_nontrue(char *str);

/* Initialization */
void		fract_prep(t_fractol *fractol);
void		window_create(t_fractol *f);
void		image_create(t_fractol *f);
void		event_init(t_fractol *f);

/* Fractal Functions */
void		mandelbrot(t_fractol *f);
void		julia(t_fractol *f);
void		set_pixel_julia(t_fractol *f, int x, int y);
void		zoom_init(t_fractol *f);
void		fract_create(t_fractol *f, char *str);

/* Complex Number Operations */
t_nbr_cmplx	sum_complex(t_nbr_cmplx z, t_nbr_cmplx c);
t_nbr_cmplx	pow_comp2(t_nbr_cmplx z);
double		pix_to_complex(double val, double min, double max, double range);

/* Image Manipulation */
void		color(t_fractol *f, int x, int y, int iter_n);
void		put_pixel(t_fractol *f, int x, int y, int color);
// Function prototypes
void	ft_putstr_fd(char *s, int fd);
void	init_mlx(t_fractol *fractal);
void	draw_fractal(t_fractol *fractal);
int	ft_strcmp(char *s1, char *s2);
int	pars_args(char *s1, char *s2);
double	ft_atof(const char *str, int *error);
#endif