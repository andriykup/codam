/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:41:37 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/04 09:41:39 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int main()
// {
//     char str1[] = "ABCDa";
//     char str2[10] = "123456789";

//     char str3[] = "ABCDa";
//     char str4[10] = "123456789";

//     printf("BEFORE:\n\n");
//     printf("My func:\n%s\n%s\n", str1, str2);
//     printf("Origin func :\n%s\n%s\n", str3, str4);

//     ft_memcpy(str2, str1, 5);
//     memcpy(str4, str3, 5);

//     printf("AFTER:\n\n");
//     printf("My func:\n%s\n%s\n", str1, str2);
//     printf("Origin func:\n%s\n%s\n", str3, str4);

//     return (0);
// }