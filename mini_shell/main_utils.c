/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:48:49 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 16:06:40 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mini_hell.h"

int	set_my_env(t_env **head)
{
	int			i;
	extern char	**environ;

	if (environ == NULL)
		return (-1);
	i = 0;
	while (environ[i])
	{
		if (add_env_node(head, environ[i]) == -1)
		{
			printf("\nError, issue setting env\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_quotes_passing(char *str, int *i, int *quotes, int *dquotes)
{
	if (str[(*i)] == '\'')
	{
		(*quotes)++;
		(*i)++;
		while (str[(*i)] != '\'' && str[(*i)] != '\0')
			(*i)++;
		if (str[(*i)] == '\'')
		{
			(*quotes)++;
			(*i)++;
		}
	}
	else if (str[(*i)] == '"')
	{
		(*dquotes)++;
		(*i)++;
		while (str[(*i)] != '"' && str[(*i)] != '\0')
			(*i)++;
		if (str[(*i)] == '"')
		{
			(*dquotes)++;
			(*i)++;
		}
	}
}

int	ft_check_inputs(char *input)
{
	int	quotes;
	int	dquotes;
	int	i;

	quotes = 0;
	dquotes = 0;
	i = 0;
	if (input[i] == '|' || input[ft_strlen(input) - 1] == '|')
		return (-1);
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
			ft_quotes_passing(input, &i, &quotes, &dquotes);
		else if (input[i] == '|' && input[i + 1] == '|')
			return (-1);
		else
			i++;
	}
	if (quotes % 2 != 0 || dquotes % 2 != 0)
		return (-1);
	return (0);
}

int	ft_check_input_0(t_mini_shell **mini_shell, char *input)
{
	int	len;

	len = ft_strlen(RED) + ft_strlen(SYN) + ft_strlen(RST);
	if (ft_check_inputs(input) != 0)
	{
		if (ft_check_inputs(input) == -1)
			write(2, RED SYN RST, len);
		(*mini_shell)->ret_value = 2;
		free(input);
		return (4);
	}
	return (0);
}

int	ft_input_check(char	*input)
{
	if (input[0] == '\0')
	{
		free(input);
		return (4);
	}
	return (0);
}
