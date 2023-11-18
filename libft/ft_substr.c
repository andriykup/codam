/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:42:29 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/10 20:42:33 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*pnt;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	pnt = (char *)malloc((len + 1) * sizeof(char));
	if (!pnt)
		return (NULL);
	while (start < ft_strlen(s) && s[start] != '\0' && i < len)
	{
		pnt[i] = s[start];
		start++;
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}
