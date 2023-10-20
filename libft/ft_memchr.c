/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:46:41 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/05 12:46:43 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char str[] = "ABCD";

//     void *pnt1 = ft_memchr(str, 'C', 5);
//     printf("My func: %s\n", (unsigned char *)pnt1);
//     void *pnt2 = memchr(str, 'C', 5);
//     printf("OR function: %s\n", (unsigned char *)pnt2);

//     return 0;
// }