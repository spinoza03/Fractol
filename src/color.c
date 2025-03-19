/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:45:25 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/18 23:45:39 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	set_color(t_fractol *f, int iter_n)
{
	if (iter_n == 0)
		f->img.color = BLACK;
	else
	{
		int red = (iter_n * 5) % 256;
		int green = (iter_n * 3) % 256;
		int blue = (iter_n * 11) % 256;
		f->img.color = (red << 16) | (green << 8) | blue;
	}
}

void	draw_pixel(t_fractol *f, int x, int y)
{
	int	pixel_index = (y * f->img.line_len) + (x * (f->img.bit_pix / 8));
	*(unsigned int *)(f->img.pix_data + pixel_index) = f->img.color;
}

void	color_pixel(t_fractol *f, int x, int y, int iter_n)
{
	set_color(f, iter_n);
	draw_pixel(f, x, y);
}