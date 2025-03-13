/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:15:03 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/11 01:31:36 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	handle_fraction(const char *str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		fraction += (*str - '0') / divisor;
		divisor *= 10.0;
		str++;
	}
	return (fraction);
}

double	ft_atof(const char *str, int *error)
{
	int		sign;
	double	result;

	sign = 1;
	result = 0.0;
	*error = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		result += handle_fraction(++str);
	return (sign * result);
}
