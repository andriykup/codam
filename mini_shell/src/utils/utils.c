/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:50:00 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/16 20:50:03 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free_2arr(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
	}
	if (arr != NULL)
		free(arr);
	arr = (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
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

int	ft_length(char const *s1, char const *s2)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			i++;
			ret++;
		}
	}
	i = 0;
	if (s2 != NULL)
	{
		while (s2[i])
		{
			i++;
			ret++;
		}
	}
	return (ret);
}
