/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:42:14 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/10 20:42:19 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pnt;
	int		i;

	i = 0;
	while (s[i])
		i++;
	pnt = (char *)malloc((i + 1) * sizeof(char));
	if (!pnt)
		return (NULL);
	i = 0;
	while (s[i])
	{
		pnt[i] = s[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}
