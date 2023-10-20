/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:57:03 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/04 09:57:05 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((dest == NULL && src == NULL))
		return (dest);
	if ((size_t)dest - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// int main()
// {
//     size_t n = 5;
//     void *src = "123456789";
//     void *dest[20];

//     ft_memmove(dest, src, n);

//     printf("%s\n", (char *)dest);

//     return (0);
// }