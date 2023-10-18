/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:57:31 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/06 10:57:33 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pnt;

	if (!(size > 0) || !(nmemb > 0))
		return (NULL);
	pnt = malloc(nmemb * size);
	if (!pnt)
		return (NULL);
	ft_bzero(pnt, nmemb * size);
	return (pnt);
}

// int main()
// {
//     void *str = ft_calloc(1, 0);
// 	if(str == NULL)
//     	printf("NULL");
//     return 0;
// }
