/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:45:43 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/03 22:45:45 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	else
		return (0);
}

// int main()
// {
//     printf("My func:\n");
//     printf("%d\n", ft_isascii('a'));
//     printf("%d\n", ft_isascii(128));
//     printf("%d\n", ft_isascii('v'));
//     printf("%d\n", ft_isascii('1'));
//     printf("%d\n", ft_isascii('.'));
//     printf("Original func:\n");
//     printf("%d\n", ft_isascii('a'));
//     printf("%d\n", ft_isascii(128));
//     printf("%d\n", ft_isascii('v'));
//     printf("%d\n", ft_isascii('1'));
//     printf("%d\n", ft_isascii('.'));
// }
