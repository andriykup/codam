/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankupins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:39:28 by ankupins          #+#    #+#             */
/*   Updated: 2023/11/24 09:39:30 by ankupins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_printstr(char *str);
int		ft_putlong(long long nb);
int		ft_printmem(void *pnt);
void	ft_swap(char *c1, char *c2);
int		ft_strlen(const char *str);
int		ft_printhexa(unsigned long long nb, char format_spec);

#endif
