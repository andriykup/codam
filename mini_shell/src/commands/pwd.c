/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 08:52:52 by ankupins          #+#    #+#             */
/*   Updated: 2024/07/05 08:52:56 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

int	com_pwd(t_mini_shell **mini_shell)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (-1);
	printf("%s\n", pwd);
	free(pwd);
	(*mini_shell)->ret_value = 0;
	return (0);
}
