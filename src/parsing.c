/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:46:55 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/13 02:21:47 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_isprint(int c)
{
	return (c > 32 && c <= 126);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_other(char *s)
{
	while (*s)
	{
		if(ft_isprint(*s))
			return (0);
		s++;
	}
	return (1);
}
int	is_valid_integer(char *str)
{
	int check;

	check = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '.')
		return (0);
	while (*str && (*str != ' ' || *str == '\t'))
	{
		if (*str == '.')
		{
			check++;
			str++;
		}
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (!check_other(str))
		return (0);
	if (check != 1)
		return(0);
	return (1);
}

int	pars_args(char *s1, char *s2)
{
	int		error;

	if (!is_valid_integer(s1))
		return (0);
	if (!is_valid_integer(s2))
		return (0);
	ft_atof(s1, &error);
	ft_atof(s2, &error);
	if (!error)
		return (0);
	return (1);
}
