/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:52:44 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/03 22:52:45 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include<string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

// int main()
// {
//     char str1[20];
//     char str2[20];
//     char str3[20];
//     char str4[20];

//     ft_memset(str1, 'A', 5);
//     ft_memset(str2, 'B', 10);

//     memset(str3, 'A', 5);
//     memset(str4, 'B', 10);

//     printf("%s\n", str1);
//     printf("%s\n", str2);
//     printf("%s\n", str3);
//     printf("%s\n", str4);
//     return 0;
// }
