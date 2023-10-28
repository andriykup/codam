/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:36:36 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/22 18:36:37 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	st_nblen(long long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb = nb * (-1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putlong(long long nb)
{
	int	ret;

	ret = st_nblen(nb);
	if (nb == 0)
		ret++;
	if (nb < 0)
	{
		ret += ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putlong(nb / 10);
		ft_putlong(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
	return (ret);
}
