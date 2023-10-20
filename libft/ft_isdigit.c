/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:45:51 by ankupins          #+#    #+#             */
/*   Updated: 2023/10/03 22:45:53 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

// int main()
// {
//     printf("My func:\n");
//     printf("%d\n", ft_isdigit(0));
//     printf("%d\n", ft_isdigit(2));
//     printf("%d\n", ft_isdigit(3));
//     printf("%d\n", ft_isdigit('5'));
//     printf("%d\n", ft_isdigit('.'));
//     printf("Original func:\n");
//     printf("%d\n", isdigit(0));
//     printf("%d\n", isdigit(2));
//     printf("%d\n", isdigit(3));
//     printf("%d\n", isdigit('5'));
//     printf("%d\n", isdigit('.'));
// }
