/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:47:09 by ankupins          #+#    #+#             */
/*   Updated: 2024/03/17 11:47:12 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		cursor++;
	while ((str[cursor + len] != separator) && str[cursor + len])
		len++;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

static int	count_words(char *str, char separator)
{
	int		word_counter;
	int		i;
	bool	inside_word;

	word_counter = 0;
	i = 0;
	while (str[i])
	{
		inside_word = false;
		while (str[i] == separator)
			i++;
		while (str[i] && str[i] != separator)
		{
			if (!inside_word)
			{
				inside_word = true;
				word_counter++;
			}
			i++;
		}
	}
	return (word_counter);
}

static long	ft_atoi(const char *nptr)
{
	long	i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}

char	**st_split(char *str, char separator)
{
	int		word_count;
	char	**strings;
	int		i;

	i = 0;
	word_count = count_words(str, separator);
	strings = malloc(sizeof(char *) * (word_count + 2));
	if (strings == NULL)
		return (NULL);
	while ((word_count - 1) >= 0)
	{
		if (i == 0)
		{
			strings[i] = malloc(sizeof(char));
			if (strings[i] == NULL)
				return (NULL);
			strings[0][0] = '\0';
			i++;
			continue ;
		}
		word_count--;
		strings[i++] = get_next_word(str, separator);
	}
	strings[i] = NULL;
	return (strings);
}

void	stack_init(t_stack_node **a, char **argv, bool argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!argc_2 && argv[i][0] == '\0')
			error_free(a, argv, argc_2);
		if (value_check(argv[i]) == 1)
			error_free(a, argv, argc_2);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_2);
		if ((repetition_check(*a, (int)nbr)) == 1)
			error_free(a, argv, argc_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (argc_2)
		free_memory(argv);
}
