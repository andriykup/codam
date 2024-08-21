/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:27:54 by aconvent          #+#    #+#             */
/*   Updated: 2024/08/09 15:01:58 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

void	dollar_sign_checker(char **res, char *str,
	t_env **env, t_mini_shell **ms)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"' && (*ms)->quotes)
			(*ms)->in_quotes = !(*ms)->in_quotes;
		if (str[i] == '\'' && (*ms)->in_quotes)
			(*ms)->quotes = !(*ms)->quotes;
		if (str[i] == '$' && (*ms)->quotes == true)
		{
			replace_dollar_sign(&str[i + 1], env, (*ms));
			if ((*ms)->env_value)
			{
				ft_strncpy(&(*res)[j], (*ms)->env_value,
					ft_strlen((*ms)->env_value));
				ft_str_increased(str, &i, ms, &j);
				continue ;
			}
		}
		(*res)[j++] = str[i++];
	}
	(*res)[j] = '\0';
}

char	*dquotes_work(char *str, t_env **env, t_mini_shell *mini_shell)
{
	char	*res;

	if (ft_strncmp(str, "\"$\'", 3) == 0 || (str[0] == '$' && str[1] == '\0')
		|| ft_strcmp(str, "\"$\"") == 0)
	{
		res = ft_strdup(str);
		free(str);
		return (res);
	}
	else if (ft_strncmp(str, "$\'", 2) == 0 && str[2] != '\0')
	{
		res = ft_strdup(&str[1]);
		free (str);
		return (res);
	}
	res = malloc(calculate_total_length(str, *env, &mini_shell) + 1);
	mini_shell->quotes = true;
	mini_shell->in_quotes = true;
	if (!res)
		return (NULL);
	dollar_sign_checker(&res, str, env, &mini_shell);
	free(str);
	return (res);
}
