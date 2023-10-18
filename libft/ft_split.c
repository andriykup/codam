/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:15:37 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/08 08:15:43 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static char	*get_word(char const *s, char c)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[len] != c && s[len])
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	i = 0;
	j = 0;
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i])
			arr[j++] = get_word(s + i, c);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	arr[j] = 0;
	return (arr);
}
