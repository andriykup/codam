/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:45:32 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/03 22:45:34 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// int main()
// {
//     printf("My func:\n");
//     printf("%d\n", ft_isalpha('a'));
//     printf("%d\n", ft_isalpha('1'));
//     printf("%d\n", ft_isalpha('.'));
//     printf("%d\n", ft_isalpha('b'));
//     printf("%d\n", ft_isalpha('c'));
//     printf("Original func:\n");
//     printf("%d\n", isalpha('a'));
//     printf("%d\n", isalpha('1'));
//     printf("%d\n", isalpha('.'));
//     printf("%d\n", isalpha('b'));
//     printf("%d\n", isalpha('c'));
// }
