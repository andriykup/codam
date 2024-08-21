/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:40:35 by aconvent          #+#    #+#             */
/*   Updated: 2024/08/09 15:02:18 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

char	*tokenizing(char *input, int *i)
{
	int		saved;
	char	*res;

	saved = *i;
	while (input[*i] && !token_delimiter(input[*i]))
	{
		if (is_quotes(input[*i]))
			skip_quotes(input, i);
		else
			(*i)++;
	}
	res = ft_substr(input, saved, (*i - saved));
	if (!res)
		return (printf("error\n"), NULL);
	return (res);
}

int	calculate_total_length(char *str, t_env *env, t_mini_shell **ms)
{
	int		total_length;
	int		i;

	i = 0;
	total_length = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '"' && (*ms)->quotes)
			(*ms)->in_quotes = !(*ms)->in_quotes;
		if (str[i] == '\'' && (*ms)->in_quotes)
			(*ms)->quotes = !(*ms)->quotes;
		if (str[i] == '$' && (*ms)->quotes)
		{
			replace_dollar_sign(&str[i + 1], &env, (*ms));
			if ((*ms)->env_value)
			{
				total_length += ft_strlen((*ms)->env_value);
				ft_str_increased(str, &i, ms, NULL);
				continue ;
			}
		}
		i++;
		total_length++;
	}
	return (total_length);
}

static int	redir_management(t_command **cmd, char *input, int *i)
{
	t_redir	*redir;

	redir = redir_init();
	if (!redir)
		return (-1);
	(*cmd)->redirected = true;
	if (get_redir(input, i, &redir) == -1)
	{
		printf("minishell : syntax error near unexpected token\n");
		free(redir);
		redir = NULL;
		return (-1);
	}
	else
		add_redir_to_end(&(*cmd)->redir, redir);
	return (0);
}

int	get_command(char *input, t_command **cmd, t_env **env, t_mini_shell *ms)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	(*cmd)->args = malloc(sizeof(char *) * (ft_strlen(input) + 1));
	while (input[i])
	{
		skip_spaces(input, &i);
		if (input[i] != '<' && input[i] != '>' && input[i] != '\0')
		{
			(*cmd)->args[j] = dquotes_work(tokenizing(input, &i), env, ms);
			if ((*cmd)->args[j++] == NULL)
				return (-1);
		}
		else if (input[i] == '<' || input[i] == '>')
		{
			if (redir_management(cmd, input, &i) == -1)
			{
				(*cmd)->args[j] = NULL;
				return (-1);
			}
		}
	}
	return ((*cmd)->args[j] = NULL, 0);
}
