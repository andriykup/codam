/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:37:26 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/07 17:37:29 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

t_env	*find_last_node(t_env *head)
{
	t_env	*last_node;

	last_node = head;
	if (head == NULL)
		return (NULL);
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

void	free_my_env(t_env **head)
{
	t_env	*current;
	t_env	*next;

	if (head == NULL)
		return ;
	current = *head;
	while (current)
	{
		free(current->key);
		free(current->value);
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_struct(t_mini_shell **mini_shell)
{
	int	i;

	i = 0;
	if ((*mini_shell)->parsed_input != NULL)
	{
		while ((*mini_shell)->parsed_input[i] != NULL)
		{
			free((*mini_shell)->parsed_input[i]);
			(*mini_shell)->parsed_input[i] = NULL;
			i++;
		}
		free((*mini_shell)->parsed_input);
		(*mini_shell)->parsed_input = NULL;
	}
	free_command_struct(mini_shell);
}

char	*st_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*result;

	len1 = strlen(s1);
	len2 = strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	strcpy(result, s1);
	strcat(result, s2);
	return (result);
}
