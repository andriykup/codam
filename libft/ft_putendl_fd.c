/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:57:47 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/09 11:57:48 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include<fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// int main()
// {
//     char str[] = "ABCD";

//     int fd = open("test.txt", O_RDWR | O_CREAT, 0666);
//     if(fd == -1)
//         printf("fd error");
//     ft_putendl_fd(str, fd);
//     close(fd);
//     return 0;
// }
