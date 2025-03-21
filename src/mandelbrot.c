/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:33:59 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/21 16:19:34 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mandelbrot_iter(double real, double imag)
{
	int		i;
	double	z_real;
	double	z_imag;
	double	temp;

	z_real = 0;
	z_imag = 0;
	i = 0;
	while (i < MAX_ITER && (z_real * z_real + z_imag * z_imag) <= 4)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp;
		i++;
	}
	return (i);
}

void	render_mandelbrot(t_fractol *f)
{
	int		x, y;
	double	real, imag;
	int		iter;
	int		color;

	y = 0;
	f->iter_n = MAX_ITER * (1 / f->zoom);
	if (f->iter_n < 30)
    	f->iter_n = 30;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = f->x_start + (x / (double)WIDTH) * (f->x_end - f->x_start);
			imag = f->y_start + (y / (double)HEIGHT) * (f->y_end - f->y_start);
			iter = mandelbrot_iter(real, imag);
			color = (iter == MAX_ITER) ? BLACK : 0xFFFFFF * iter / MAX_ITER;
			*(int *)(f->img.pix_data + (y * f->img.line_len + x * (f->img.bit_pix / 8))) = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_init_ptr, f->mlx_win_ptr, f->img.img_ptr, 0, 0);
}