/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:47:35 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/18 23:47:46 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_pixel_julia(t_fractol *f, int x, int y)
{
	t_nbr_cmplx	z;

	// Convert pixel coordinates to complex plane coordinates
	z.real = pix_cor_to_complexcor(x, f->x_start, f->x_end, WIDTH);
	z.img = pix_cor_to_complexcor(y, f->y_start, f->y_end, HEIGHT);
	
	f->iter_n = 0;
	while (f->iter_n < MAX_ITER)
	{
		z = sum_complex(pow_comp2(z), f->c_julia);
		if ((z.real * z.real) + (z.img * z.img) > 4)
		{
			color(f, x, y, f->iter_n);
			return;
		}
		f->iter_n++;
	}
	put_pixel(f, x, y, BLACK);
}

void	julia(t_fractol *f)
{
	int	x, y;

	zoom_init(f);  // Initialize zoom before drawing

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
			set_pixel_julia(f, x, y);
	}

	mlx_put_image_to_window(f->mlx_init_ptr, f->mlx_win_ptr, f->img.img_ptr, 0, 0);
}