/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:12:37 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/11 10:12:40 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(char const *s1, char const *s2)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (s1[i])
	{
		i++;
		ret++;
	}
	i = 0;
	while (s2[i])
	{
		i++;
		ret++;
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		ret_i;
	char	*ret;
	int		length;

	length = ft_length(s1, s2);
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
	return (ret);
}

// int main()
// {
//     char s1[] = "12345";
//     char s2[] = "67890";

//     char *pnt = ft_strjoin(s1, s2);

//     printf("%s\n", pnt);

//     return 0;
// }
