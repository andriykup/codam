/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:11:07 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 15:26:29 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

int	com_env(char**command, t_env **head, t_mini_shell **mini_shell)
{
	t_env	*current;

	if (command != NULL && command[1] != NULL)
	{
		printf("env: %s: No such file or directory\n", command[1]);
		exit(127);
	}
	current = *head;
	while (current != NULL)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
	(*mini_shell)->ret_value = 0;
	return (0);
}

void	*update_pwd(t_env *head)
{
	t_env	*temp_node;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	temp_node = find_env_var(&head, "PWD");
	if (temp_node == NULL)
	{
		printf("PWD dont exist :(\n");
		printf("now im sad because i can not update it :(\n");
		free(pwd);
		return (NULL);
	}
	free(temp_node->value);
	temp_node->value = ft_strdup(pwd);
	free(pwd);
	return (0);
}

void	*update_old_pwd(t_env *head)
{
	t_env	*temp_node;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	temp_node = find_env_var(&head, "OLDPWD");
	if (temp_node == NULL)
	{
		printf("OLDPWD dont exist :(\n");
		printf("now im sad because i can not update it :(\n");
		free(pwd);
		return (NULL);
	}
	free(temp_node->value);
	temp_node->value = ft_strdup(pwd);
	free(pwd);
	return (0);
}
