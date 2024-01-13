/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:03:48 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/09 08:03:51 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include<stdlib.h>

// char ft_transform(unsigned int index, char c) {
//     if (c >= 'a' && c <= 'z') {
//         return c - ('a' - 'A');
//     }
//     return c;
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (!s)
		return (NULL);
	ret = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
