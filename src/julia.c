/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:34:38 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/21 16:32:21 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	julia_iter(double z_real, double z_imag, double c_real, double c_imag, int iter_n)
{
	int		i;
	double	temp;

	i = 0;
	while (i < iter_n && (z_real * z_real + z_imag * z_imag) <= 4)
	{
		temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = temp;
		i++;
	}
	return (i);
}

void	render_julia(t_fractol *f, double c_real, double c_imag)
{
	int		x;
	int		y;
	double	z_real;
	double	z_imag;
	int		iter;
	int		color;

	f->iter_n = MAX_ITER * (1.0 / f->zoom);
	if (f->iter_n < 30)
		f->iter_n = 30;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z_real = f->x_start + (x / (double)WIDTH) * (f->x_end - f->x_start);
			z_imag = f->y_start + (y / (double)HEIGHT) * (f->y_end - f->y_start);
			iter = julia_iter(z_real, z_imag, c_real, c_imag, f->iter_n);
			color = 0;
			if (iter != f->iter_n)
				color = (0xFFFFFF * iter) / f->iter_n;
			*(int *)(f->img.pix_data + (y * f->img.line_len
					+ x * (f->img.bit_pix / 8))) = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_init_ptr, f->mlx_win_ptr, f->img.img_ptr, 0, 0);
}
