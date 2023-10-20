/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:44:47 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/03 22:44:54 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// int main()
// {
//     printf("My func:\n");
//     printf("%d\n", ft_isalnum('a'));
//     printf("%d\n", ft_isalnum('n'));
//     printf("%d\n", ft_isalnum('v'));
//     printf("%d\n", ft_isalnum('1'));
//     printf("%d\n", ft_isalnum('.'));
//     printf("Original func:\n");
//     printf("%d\n", ft_isalnum('a'));
//     printf("%d\n", ft_isalnum('n'));
//     printf("%d\n", ft_isalnum('v'));
//     printf("%d\n", ft_isalnum('1'));
//     printf("%d\n", ft_isalnum('.'));
// }
