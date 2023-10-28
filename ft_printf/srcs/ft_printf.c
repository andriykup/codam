/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:32:20 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/19 19:32:22 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	st_print(const char format, va_list args)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (format == 's')
		ret += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		ret += ft_printmem(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		ret += ft_putlong(va_arg(args, int));
	else if (format == 'u')
		ret += ft_putlong(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		ret += ft_printhexa(va_arg(args, unsigned int), format);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	if (str == NULL)
		return (-1);
	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				ret += ft_putchar('%');
			else
				ret += st_print(str[i + 1], args);
			i++;
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
