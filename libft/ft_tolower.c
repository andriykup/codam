/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:17:40 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/05 10:17:42 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include<ctype.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

// int main()
// {
//     char a = 'A';
//     char b = 'B';

//     printf("BEFORE:\na = %c\nb = %c\n\n", a, b);

//     a = ft_tolower(a);
//     b = tolower(b);

//     printf("AFTER:\na = %c\nb = %c\n", a, b);

// }
