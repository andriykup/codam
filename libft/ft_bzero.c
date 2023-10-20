/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:13:44 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/04 09:13:45 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

// int main()
// {
//     char str1[] = "AAAAAAAAAAAAAAAA";
//     char str2[] = "AAAAAAAAAAAAAAAA";
//     char str3[] = "AAAAAAAAAAAAAAAA";
//     char str4[] = "AAAAAAAAAAAAAAAA";

//     ft_bzero(str1, 5);
//     ft_bzero(str2, 5);
//     bzero(str3, 5);
//     bzero(str4, 5);

//     printf("%s\n", str1);
//     printf("%s\n", str2);
//     printf("%s\n", str3);
//     printf("%s\n", str4);

//     return (0);
// }
