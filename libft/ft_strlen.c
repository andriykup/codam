/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:46:06 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/03 22:46:07 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int main()
// {
//     printf("My func:\n");
//     printf("%zu\n", ft_strlen("12345"));
//     printf("%zu\n", ft_strlen("QWERTa"));

//     printf("Original func:\n");
//     printf("%zu\n", strlen("12345"));
//     printf("%zu\n", strlen("QWERTa"));
// }
