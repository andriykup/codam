/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:38:10 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/04 10:38:13 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include<bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i_src;

	i_src = 0;
	while (src[i_src])
		i_src++;
	i = 0;
	if (size == 0)
		return (i_src);
	while (i < size - 1 && src[i] != '\0' && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i_src);
}

// int main()
// {
//     char str1[] = "ABCD123";
//     char str2[10];
//     char str3[] = "ABCD123";
//     char str4[10];

//     printf("my func:\n");
//     printf("BEFORE:\nstr1: %s\nstr2: %s\n\n", str1, str2);
//     int return1 = ft_strlcpy(str2, str1, 2);
//     printf("AFTER:\nstr1: %s\nstr2: %s\nreturn: %d\n\n", 
// 		str1, str2, return1);
//     printf("\nOrigin func:\n");
//     printf("BEFORE:\nstr3: %s\nstr4: %s\n\n", str3, str4);
//     int return2 = strlcpy(str4, str3, 2);
//     printf("AFTER:\nstr3: %s\nstr4: %s\nreturn: %d\n\n",
// 			str3, str4, return2);
//     return (0);
// }
