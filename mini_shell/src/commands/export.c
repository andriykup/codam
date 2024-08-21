/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:52:41 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 15:29:17 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

int	add_env_node(t_env **head, char *env)
{
	t_env	*new_env;
	t_env	*last_env;
	char	**splited_env_var;

	splited_env_var = ft_split(env, '=');
	new_env = ft_new_node(splited_env_var);
	if (new_env == NULL)
		return (-1);
	ft_free_2arr(splited_env_var);
	if (*head == NULL)
	{
		*head = new_env;
		return (0);
	}
	last_env = find_last_node(*head);
	if (last_env == NULL)
		return (-1);
	else
		new_env->prev = last_env;
	last_env->next = new_env;
	return (0);
}

static void	update_env_node(t_env **env_node, char *env)
{
	char	**splited_env_var;

	splited_env_var = ft_split(env, '=');
	free((*env_node)->value);
	(*env_node)->value = ft_strdup(splited_env_var[1]);
	ft_free_2arr(splited_env_var);
}

t_env	*find_env_var(t_env **head, char *env)
{
	t_env	*current;
	char	**splited_env_var;

	if (env == NULL)
		return (NULL);
	current = *head;
	splited_env_var = ft_split(env, '=');
	while (current != NULL)
	{
		if (ft_strcmp(splited_env_var[0], current->key) == 0)
		{
			ft_free_2arr(splited_env_var);
			return (current);
		}
		current = current->next;
	}
	ft_free_2arr(splited_env_var);
	return (NULL);
}

static void	com_export_p2(t_env **head, t_mini_shell **mini_shell,
	char **temp1, char *new_env_var)
{
	t_env	*temp;

	temp = NULL;
	if (temp1[0] == NULL || temp1[1] == NULL )
	{
		free(temp1[0]);
		free(temp1);
		error_export(new_env_var);
		(*mini_shell)->ret_value = 1;
		return ;
	}
	temp = find_env_var(head, new_env_var);
	if (temp == NULL)
		add_env_node(head, new_env_var);
	else
		update_env_node(&temp, new_env_var);
	ft_free_2arr(temp1);
	(*mini_shell)->ret_value = 0;
}

void	com_export(t_env **head, char **new_env_var, t_mini_shell **mini_shell)
{
	char	**temp1;
	int		i;

	if (!new_env_var[1])
	{
		com_env(NULL, head, mini_shell);
		return ;
	}
	i = 1;
	while (new_env_var[i])
	{
		temp1 = ft_split(new_env_var[i], '=');
		com_export_p2(head, mini_shell, temp1, new_env_var[i]);
		i++;
	}
}
