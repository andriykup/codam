/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:35:31 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/09 11:35:32 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int main()
// {
//     char str[] = "ABCD";

//     int fd = open("test.txt", O_RDWR | O_CREAT, 0666);
//     if(fd == -1)
//         printf("fd error");	
//     ft_putstr_fd(str, fd);	
//     close(fd);
//     return 0;
// }