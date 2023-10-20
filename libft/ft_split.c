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

static void	*ft_free_memory(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

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

static char	*get_word(char const *s, char c, int *idx)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[len] != c && s[len])
		len++;
	*idx += len;
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
	arr[words] = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i])
			arr[j++] = get_word(s + i, c, &i);
		if (j > 0 && arr[j - 1] == NULL)
			return (ft_free_memory(arr));
	}
	return (arr);
}

// int main()
// {
//     char str[] = " 123  123 12 2123";
//     char c = ' ';

//     char **ret = ft_split(str, c);
//     int i = 0;
//     while(ret[i])
//     {
//         printf("%s\n", ret[i]);
//         i++;
//     }  

//     return 0;
// }
