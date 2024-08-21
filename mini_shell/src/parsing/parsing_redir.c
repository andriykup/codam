/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:34:51 by aconvent          #+#    #+#             */
/*   Updated: 2024/07/20 13:26:10 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

int	redir_in(char *str, int *i, t_redir **redi)
{
	char	*temp;

	if (str[*i + 1] != '<' && str[*i + 1] != '\0')
	{
		(*redi)->redir = ft_strdup("<");
		(*i)++;
	}
	else if (str[*i + 1] == '<' && str[*i + 2] != '<' && str[*i + 2] != '\0')
	{
		(*redi)->redir = ft_strdup("<<");
		(*i) = (*i) + 2;
	}
	skip_spaces(str, i);
	if (str[(*i)] == '\0' || str[(*i)] == '<' || str[(*i)] == '>')
	{
		free ((*redi)->redir);
		return (-1);
	}
	temp = tokenizing(str, i);
	if (ft_strcmp((*redi)->redir, "<") == 0)
		(*redi)->file_name = command_quotes(temp);
	else if (ft_strcmp((*redi)->redir, "<<") == 0)
		(*redi)->delimiter = command_quotes(temp);
	free(temp);
	return (0);
}

int	redir_out(char *str, int *i, t_redir **redi)
{
	char	*temp;

	if (str[*i + 1] != '>' && str[*i + 1] != '\0')
	{
		(*redi)->redir = ft_strdup(">");
		(*i)++;
	}
	else if (str[*i + 1] == '>' && str[*i + 2] != '>' && str[*i + 2] != '\0')
	{
		(*redi)->redir = ft_strdup(">>");
		(*i) = (*i) + 2;
	}
	skip_spaces(str, i);
	if (str[(*i)] == '\0' || str[(*i)] == '>' || str[(*i)] == '<')
	{
		free ((*redi)->redir);
		return (-1);
	}
	temp = tokenizing(str, i);
	(*redi)->file_name = command_quotes(temp);
	free(temp);
	return (0);
}

int	get_redir(char *str, int *i, t_redir **redir)
{
	int	j;

	j = 0;
	if (str[*i] == '<')
	{
		if (redir_in(str, i, &(*redir)) == -1)
			return (-1);
	}
	else if (str[(*i)] == '>')
	{
		if (redir_out(str, i, &(*redir)) == -1)
		{
			return (-1);
		}
	}
	return (0);
}
