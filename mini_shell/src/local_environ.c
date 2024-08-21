/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:35:06 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/07 18:35:07 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_hell.h"

static int	ft_my_env_length(t_env *my_env)
{
	t_env	*current;
	int		i;

	current = my_env;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

static void	ft_join_str1(char *ret, const char *s1, int *ret_i)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		ret[*ret_i] = s1[i];
		i++;
		(*ret_i)++;
	}
}

static char	*ft_strjoin_environ(char const *s1, char const *s2)
{
	int		i;
	int		ret_i;
	char	*ret;
	int		length;

	length = ft_length(s1, s2);
	ret = (char *)malloc((length + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	ret_i = 0;
	if (s1 != NULL)
		ft_join_str1(ret, s1, &ret_i);
	ret[ret_i++] = '=';
	i = 0;
	if (s2 != NULL)
	{
		while (s2[i])
		{
			ret[ret_i] = s2[i];
			i++;
			ret_i++;
		}
	}
	ret[ret_i] = '\0';
	return (ret);
}

void	*ft_local_environ(t_mini_shell **mini_shell, t_env *my_env)
{
	t_env	*current;
	int		my_env_length;
	int		i;

	current = my_env;
	i = 0;
	my_env_length = ft_my_env_length(my_env);
	(*mini_shell)->local_environ = malloc(sizeof(char *) * (my_env_length + 1));
	if ((*mini_shell)->local_environ == NULL)
		return (NULL);
	while (current)
	{
		(*mini_shell)->local_environ[i] = ft_strjoin_environ(current->key,
				current->value);
		i++;
		current = current->next;
	}
	(*mini_shell)->local_environ[i] = NULL;
	return (0);
}
