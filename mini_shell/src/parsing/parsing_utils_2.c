/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:29:48 by aconvent          #+#    #+#             */
/*   Updated: 2024/07/01 15:34:13 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' \
	|| c == '\v' || c == '\f' || c == '\r');
}

bool	token_delimiter(char c)
{
	return (c == ' ' || c == '\v' || c == '\f' || c == '\r' \
	|| c == '\t' || c == '\n' || c == '<' || c == '>');
}

bool	is_quotes(char c)
{
	return (c == '\'' || c == '\"');
}
