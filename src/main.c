/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:01:05 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/13 01:41:00 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main (int ac, char **av)
{
	if (ac > 1 && ac <= 4)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
		{
			printf("m3alm\n");
		}
		else if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
		{
			if(!pars_args(av[2],av[3])) 
			{
				printf("fratiha\n");
			}
			else
			printf("m3alm\n");
		}
		else
			printf("fretiha\n");
	}	
}
