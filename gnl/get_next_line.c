/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:58:58 by ankupins          #+#    #+#             */
/*   Updated: 2023/11/15 10:59:02 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_endlinecheck(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_processtring(char *left_over)
{
	size_t	i;
	char	*str;

	i = 0;
	while (left_over[i] != '\n' && left_over[i] != '\0')
		i++;
	if (left_over[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (left_over[i] != '\n' && left_over[i] != '\0')
	{
		str[i] = left_over[i];
		i++;
	}
	if (left_over[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_processleftover(char *left_over)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (left_over[y] != '\n' && left_over[y] != '\0')
		y++;
	if (left_over[y] == '\n')
		y++;
	while (left_over[y])
	{
		left_over[i] = left_over[y];
		y++;
		i++;
	}
	left_over[i] = '\0';
	return (left_over);
}

static char	*ft_read_line(int fd, char *left_over)
{
	static char	temp[BUFFER_SIZE + 1];
	int			char_read;

	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, temp, BUFFER_SIZE);
		if (char_read == -1)
			return (free (left_over), NULL);
		temp[char_read] = '\0';
		left_over = ft_strjoin(left_over, temp);
		if (!left_over)
			return (NULL);
		if (ft_endlinecheck(left_over) == 1)
			break ;
	}
	if (left_over[0] == 0)
	{
		free(left_over);
		left_over = NULL;
		return (NULL);
	}
	return (left_over);
}

char	*get_next_line(int fd)
{
	static char	*left_over = NULL;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (left_over == NULL)
		left_over = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!left_over)
		return (NULL);
	left_over = ft_read_line(fd, left_over);
	if (!left_over)
		return (NULL);
	ret = ft_processtring(left_over);
	left_over = ft_processleftover(left_over);
	return (ret);
}
