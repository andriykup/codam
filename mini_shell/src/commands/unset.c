/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:53:01 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/06 12:26:47 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

static void	free_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

int	com_unset(t_env **head, char *env, t_mini_shell **mini_shell)
{
	t_env	*node;

	node = find_env_var(head, env);
	if (node == NULL)
	{
		(*mini_shell)->ret_value = 0;
		return (-1);
	}
	if (node == *head)
	{
		node->next->prev = NULL;
		*head = node->next;
	}
	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		head = &node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free_node(node);
	(*mini_shell)->ret_value = 0;
	return (0);
}
