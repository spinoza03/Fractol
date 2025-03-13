/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:38:05 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/10 16:40:36 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_strcmp(char *s1, char *s2);
int	pars_args(char *s1, char *s2);
double	ft_atof(const char *str, int *error);
#endif