/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:47:51 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/06 09:47:53 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i_little;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i <= len)
	{
		i_little = 0;
		while ((little[i_little] == big[i + i_little])
			&& (i + i_little) <= (len - 1))
		{
			if (little[i_little + 1] == '\0')
				return ((char *)big + i);
			i_little++;
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char str1[] = "ABCD";
//     char str2[] = "D";

//     printf("MY func: %s\n", ft_strnstr(str1, str2, 4));
//     printf("OR func: %s\n", strnstr(str1, str2, 4));

//     return 0;
// }