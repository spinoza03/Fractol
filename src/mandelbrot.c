/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:01:14 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/19 00:13:45 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_pixel_mandelbrot(t_fractol *f, int x, int y)
{
	t_nbr_cmplx	z;
	t_nbr_cmplx	c;

	z.real = 0.0;
	z.img = 0.0;
	f->iter_n = 0;
	c.real = pix_to_complex(x, f->x_start, f->x_end, WIDTH);
	c.img = pix_to_complex(y, f->y_start, f->y_end, HEIGHT);
	while (f->iter_n < MAX_ITER)
	{
		z = sum_complex(pow_comp2(z), c);
		if ((z.real * z.real) + (z.img * z.img) > 4)
		{
			color(f, x, y, f->iter_n);
			return ;
		}
		f->iter_n++;
	}
	put_pixel(f, x, y, BLACK);
}

void	mandelbrot(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	zoom_init(f);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_pixel_mandelbrot(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_init_ptr,
		f->mlx_win_ptr, f->img.img_ptr, 0, 0);
}