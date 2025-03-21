/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:38:05 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/21 16:30:07 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define HEIGHT	900
# define WIDTH	900
# define MAX_ITER 100
# define BLACK 0X000000

# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define ZOOM_IN 4
# define ZOOM_OUT 5

typedef struct s_check
{
	int	s;
	int	non_true;
	int	f;
	int	digit;
	int	prev;
}	t_check;

typedef struct s_nbr_cmplx
{
	double	real;
	double	img;
}		t_nbr_cmplx;

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
	void		*mlx_init_ptr;
	void		*mlx_win_ptr;
	char		*title;
	int			iter_n;
	int			fractal_type;
	double		x_start;
	double		x_end;
	double		y_start;
	double		y_end;
	t_img_data	img;
	t_nbr_cmplx	c_julia;
}	t_fractol;

void	put_pixel(t_fractol *f, int x, int y, int color);
int	close_window(t_fractol *f);
int	mouse_hook(int button, int x, int y, t_fractol *f);
int	key_hook(int keycode, t_fractol *f);
void	init_fractol(t_fractol *f, char *title);
void	init_image(t_fractol *f);
void	ft_putstr_fd(char *s, int fd);
void	init_mlx(t_fractol *fractal, char *title);
void	draw_fractal(t_fractol *fractal);
int	ft_strcmp(char *s1, char *s2);
int	pars_args(char *s1, char *s2);
double	ft_atof(const char *str, int *error);
void	render_julia(t_fractol *f, double c_real, double c_imag);
void	render_mandelbrot(t_fractol *f);
#endif