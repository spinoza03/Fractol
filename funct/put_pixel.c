/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:29:40 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/21 16:29:58 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	int	pixel_index;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_index = (y * f->img.line_len) + (x * (f->img.bit_pix / 8));
		*(int *)(f->img.pix_data + pixel_index) = color;
	}
}