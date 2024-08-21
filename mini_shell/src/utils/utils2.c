/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:35:35 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 12:15:50 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

char	*ft_spaceout(char *input)
{
	char	*res;
	int		len;
	int		i;
	int		j;
	int		end_str;

	end_str = ft_strlen(input) - 1;
	i = 0;
	j = 0;
	len = ft_strlen(input);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (input[i] == ' ' && input[i] != '\0')
		i++;
	while (input[i] != '\0')
		res[j++] = input[i++];
	while (ft_isspace(res[end_str--]) && end_str > 0)
	{
		res[j] = '\0';
		j--;
	}
	res[j] = '\0';
	free(input);
	return (res);
}

char	*get_env_path(t_env *my_env)
{
	char	*env_path;
	t_env	*current;

	current = my_env;
	while (current != NULL)
	{
		if (ft_strncmp(current->key, "PATH", 4) == 0)
		{
			env_path = ft_strdup(current->value);
			return (env_path);
		}
		current = current->next;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
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

char	*ft_strdup(const char *s)
{
	char	*pnt;
	int		i;

	if (s == NULL)
		return (NULL);
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
