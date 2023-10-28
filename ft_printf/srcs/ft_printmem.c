/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:37:39 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/22 18:37:40 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printmem(void *pnt)
{
	int	ret;

	ret = 0;
	if (!pnt)
		return (ft_printstr("(nil)"));
	if (&pnt == (void *)-1)
		return (ft_printstr("0xffffffffffffffff"));
	ret = 0;
	ret += ft_printstr("0x");
	ret += ft_printhexa((unsigned long long)pnt, 'x');
	return (ret);
}
