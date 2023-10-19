/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:01:52 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/05 09:01:54 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_i;
	size_t	dst_i;

	dst_i = 0;
	src_i = ft_strlen(src);
	while (dst_i < size && dst[dst_i])
		dst_i++;
	if (dst_i == size)
		return (size + src_i);
	if (src_i < size - dst_i)
		ft_memcpy(dst + dst_i, src, src_i + 1);
	else
	{
		ft_memcpy(dst + dst_i, src, size - dst_i - 1);
		dst[size - 1] = '\0';
	}
	return (dst_i + src_i);
}
