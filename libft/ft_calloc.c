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
	void	*pnt;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	pnt = malloc(nmemb * size);
	if (!pnt)
		return (NULL);
	ft_bzero(pnt, nmemb * size);
	return (pnt);
}

// int main()
// {
//     printf("My func: %s\n", (char *)ft_calloc(5,-15));
//     printf("My func: %s\n", (char *)calloc(5,-15));
//     return 0;
// }
