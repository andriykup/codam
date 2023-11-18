/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:59:26 by ankupins          #+#    #+#             */
/*   Updated: 2023/11/15 10:59:30 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		ret_i;
	char	*ret;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc((length + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret_i = 0;
	while (s1[ret_i])
	{
		ret[ret_i] = s1[ret_i];
		ret_i++;
	}
	i = 0;
	while (s2[i])
	{
		ret[ret_i] = s2[i];
		i++;
		ret_i++;
	}
	ret[ret_i] = '\0';
	free (s1);
	return (ret);
}
