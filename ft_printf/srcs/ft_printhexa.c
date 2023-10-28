/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:40:03 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/22 18:40:05 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	st_formatspec(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

int	ft_printhexa(unsigned long long nb, char format_spec)
{
	char	result[20];
	char	*hex;
	int		i;
	int		rev_i;

	hex = "0123456789ABCDEF";
	i = 0;
	rev_i = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		result[i] = hex[nb % 16];
		nb = nb / 16;
		i++;
	}
	result[i] = '\0';
	while (rev_i < i)
		ft_swap(&result[rev_i++], &result[--i]);
	if (format_spec == 'x')
		st_formatspec(result);
	return (ft_printstr(result));
}
