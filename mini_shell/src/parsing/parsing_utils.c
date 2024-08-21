/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:28:18 by aconvent          #+#    #+#             */
/*   Updated: 2024/07/18 15:25:30 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

void	skip_spaces(char *str, int *i)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

void	skip_quotes(char *str, int *i)
{
	char	quote;

	quote = str[*i];
	(*i)++;
	while (str[*i] != quote && str[*i] != '\0')
	{
		(*i)++;
	}
	if (str[*i] == quote)
		(*i)++;
}

char	*get_env_value(const char *key, t_env *env)
{
	if (key[0] == '\'')
		return (ft_strjoin("$", key));
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (ft_strdup("\0"));
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
