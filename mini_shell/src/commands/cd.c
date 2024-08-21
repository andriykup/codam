/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:52:10 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 15:28:16 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

void	empty_cd(t_env *head, t_mini_shell **mini_shell)
{
	t_env	*temp_node;

	update_old_pwd(head);
	temp_node = find_env_var(&head, "HOME");
	if (temp_node == NULL)
	{
		write(2, "cd: ", 4);
		write(2, "you unseted HOME :(\n", 21);
		(*mini_shell)->ret_value = 1;
		return ;
	}
	chdir(temp_node->value);
	update_pwd(head);
	return ;
}

static void	ft_free(char *new_path, char *full_path)
{
	free(new_path);
	free(full_path);
}

static char	*create_new_path(void)
{
	char	*new_path;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (NULL);
	new_path = st_strjoin(pwd, "/");
	if (new_path == NULL)
	{
		free(pwd);
		return (NULL);
	}
	free(pwd);
	return (new_path);
}

void	*com_cd(char *path, t_env *head, t_mini_shell **mini_shell)
{
	char	*new_path;
	char	*full_path;

	if (strncmp(path, "/home/", 6) == 0)
		chdir("/");
	update_old_pwd(head);
	new_path = create_new_path();
	if (new_path == NULL)
		return (ft_error("cd", NULL));
	full_path = st_strjoin(new_path, path);
	if (full_path == NULL)
		return (free(new_path), NULL);
	if (chdir(full_path) < 0)
	{
		ft_error(path, NULL);
		(*mini_shell)->ret_value = 1;
		ft_free(new_path, full_path);
		return (0);
	}
	update_pwd(head);
	ft_free(new_path, full_path);
	(*mini_shell)->ret_value = 0;
	return (0);
}
