/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:09:58 by ankupins          #+#    #+#             */
/*   Updated: 2024/04/11 17:10:01 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_exit(void)
{
	ft_putstr_fd("incorrect argument for julia :(\n", 1);
	exit (1);
}

static double	ft_exponent(char *str)
{
	int		i;
	double	exponent;

	exponent = 0.0;
	i = 0;
	if (str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_exit();
	while (str[i] && str[i] != '.')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			exponent = exponent * 10.0 + (str[i] - '0');
		}
		else
			ft_exit();
		i++;
	}
	return (exponent);
}

static double	ft_decimal(char *str)
{
	int		i;
	double	decimal;

	i = 0;
	decimal = 0.0;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			decimal = decimal * 10.0 + (str[i] - '0');
			i++;
		}
		else
			ft_exit();
	}
	return (decimal);
}

static double	ft_set_decimal(char *str, double exponent, double decimal)
{
	double	result;
	int		i;
	int		decimal_i;

	i = 0;
	decimal_i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i++])
		decimal_i++;
	while (decimal_i > 0)
	{
		decimal = decimal / 10.0;
		decimal_i--;
	}
	result = exponent + decimal;
	return (result);
}

double	ft_atof(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	i = 0;
	sign = 0;
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	result = ft_exponent(str);
	decimal = ft_decimal(str);
	result = ft_set_decimal(str, result, decimal);
	if (sign == 1)
		result = result * -1;
	return (result);
}
