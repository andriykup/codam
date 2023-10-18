/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:55:19 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/05 09:55:21 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include<ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

// int main()
// {
//     char a = 'a';
//     char b = 'b';

//     printf("BEFORE:\na = %c\nb = %c\n\n", a, b);

//     a = ft_toupper(a);
//     b = toupper(b);

//     printf("AFTER:\na = %c\nb = %c\n", a, b);

// }