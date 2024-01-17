/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:30:40 by ankupins          #+#    #+#             */
/*   Updated: 2024/01/12 12:30:43 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	free_mem(char **paths_envp)
{
	int	y;

	y = 0;
	while (paths_envp[y])
	{
		free(paths_envp[y]);
		y++;
	}
	free (paths_envp);
}

char	**get_env_path(char **envp)
{
	char	*path;

	path = NULL;
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp != NULL)
		path = *envp + 5;
	if (*path != '\0')
		return (ft_split(path, ':'));
	free(path);
	return (NULL);
}

char	*find_cmd_path(char **paths_envp, char *cmd)
{
	int		i;
	char	*full_cmd;
	char	*ret;

	if (paths_envp == NULL)
		return (NULL);
	full_cmd = ft_strjoin("/", cmd);
	if (full_cmd == NULL)
		return (NULL);
	i = 0;
	while (paths_envp[i])
	{
		ret = ft_strjoin(paths_envp[i], full_cmd);
		if (access(ret, X_OK) != -1)
		{
			free(full_cmd);
			return (ret);
		}
		i++;
	}
	free(ret);
	free(full_cmd);
	return (NULL);
}
