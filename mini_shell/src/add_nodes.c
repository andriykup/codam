/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 08:46:47 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/21 08:46:48 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_hell.h"

void	add_command_to_end(t_command **head, t_command *new_node)
{
	t_command	*current;

	if (head == NULL || new_node == NULL)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	add_redir_to_end(t_redir **head, t_redir *new_node)
{
	t_redir	*current;

	if (head == NULL || new_node == NULL)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
