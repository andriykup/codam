/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:08:34 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/09 10:08:37 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main()
// {
//     char c = 'c';

//     int fd = open("test.txt", O_WRONLY | O_CREAT);
//     printf("fd = %d\n", fd); 

//     if (fd == -1)
//         printf("fd error :("); 

//     ft_putchar_fd(c, fd);

//     close(fd);

//     return 0;
// }