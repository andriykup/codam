/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:59:16 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/11 07:59:26 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ret;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && isset(s1[start], set))
		start++;
	while (end > start && isset(s1[end - 1], set))
		end--;
	ret = (char *)malloc((end - start + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (start + i < end)
	{
		ret[i] = s1[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// int main()
// {
// 	char str[] = "AABC ASJDSAJ BBCAA";
// 	char set[] = "AB";
// 	char *pnt = ft_strtrim(str, set);

// 	printf("%s\n", pnt);

// 	return 0;
// }
