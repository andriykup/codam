/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:31:07 by ankupins          #+#    #+#             */
/*   Updated: 2024/01/12 12:31:09 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

void	exec_child_process_1(int f1, int *end, char **argv, char **paths_envp);
void	exec_child_process_2(int f2, int *end, char **argv, char **paths_envp);
char	**get_env_path(char **envp);
void	free_mem(char **paths_envp);
char	*find_cmd_path(char **paths_envp, char *cmd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
