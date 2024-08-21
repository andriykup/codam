/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:35:04 by aconvent          #+#    #+#             */
/*   Updated: 2024/07/18 12:13:46 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mini_hell.h"

int	count_words(char *input)
{
	char	quotes;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|')
			count++;
		if (input[i] == '"' || input[i] == '\'')
		{
			quotes = input[i++];
			while (input[i] != quotes && input[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (i);
}

int	count_chars(char *input)
{
	char	quotes;
	int		i;

	i = 0;
	while (input[i] != '|' && input[i] != '\0')
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			quotes = input[i++];
			while (input[i] != quotes && input[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (i);
}

char	*ft_copy_string(char *input, int *i)
{
	char	quotes;
	char	*res;
	int		j;

	j = 0;
	res = malloc(sizeof(char) * (count_chars(&input[(*i)]) + 1));
	while (input[(*i)] != '|' && input[(*i)] != '\0')
	{
		if (input[(*i)] == '"' || input[(*i)] == '\'')
		{
			quotes = input[(*i)];
			res[j++] = input[(*i)++];
			while (input[(*i)] != quotes && input[(*i)] != '\0')
				res[j++] = input[(*i)++];
			res[j++] = input[(*i)++];
		}
		else
			res[j++] = input[(*i)++];
	}
	res[j] = '\0';
	return (res);
}

char	**ft_split_pipes(char *input)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (count_words(input) + 1));
	if (res == NULL)
		return (NULL);
	while (input[i])
	{
		if (res == NULL)
			return (NULL);
		skip_spaces(input, &i);
		res[j] = ft_copy_string(input, &i);
		if (input[i] == '|' && input[i + 1] != '|')
			i++;
		else if (input[i] == '|' && input[i + 1] == '|')
			return (NULL);
		j++;
	}
	res[j] = NULL;
	return (res);
}
