/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:27:19 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/08 09:27:20 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		i++;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	negative_num(char *ret, int n)
{
	ret[0] = '-';
	return (n = n * -1);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	len = get_len(n);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[len--] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (n == -2147483648)
	{
		ret[0] = '-';
		ret[1] = '2';
		n = 147483648;
	}
	if (n < 0)
		n = negative_num(ret, n);
	while (n > 0)
	{
		ret[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (ret);
}
