/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:45:58 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/03 22:46:00 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int main()
// {
//     printf("My func:\n");
//     printf("%d\n", ft_isprint(128));
//     printf("%d\n", ft_isprint('1'));
//     printf("%d\n", ft_isprint('g'));
//     printf("Original func:\n");
//     printf("%d\n", isprint(128));
//     printf("%d\n", isprint('1'));
//     printf("%d\n", isprint('g'));
// }
