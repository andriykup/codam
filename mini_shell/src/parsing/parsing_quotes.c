/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:08:57 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 15:30:16 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_hell.h"

char	*command_quotes(char *str)
{
	int		i;
	bool	quotes;
	bool	dquotes;

	quotes = true;
	dquotes = true;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && dquotes == true)
		{
			quotes = !quotes;
			quotes_out(&str[i], &str[i + 1]);
		}
		else if (str[i] == '"' && quotes == true)
		{
			dquotes = !dquotes;
			quotes_out(&str[i], &str[i + 1]);
		}
		else
			i++;
	}
	if (!quotes || !dquotes)
		return (NULL);
	return (ft_strdup(str));
}

char	*ft_ret_val(char *temp, t_mini_shell *ms)
{
	char	*res;
	char	*temp_val;
	int		i;
	int		j;

	j = 0;
	i = 1;
	res = malloc(sizeof(char ) * (ft_strlen(temp) + 4));
	if (res == NULL)
		return (NULL);
	temp_val = ft_itoa(ms->ret_value);
	while (temp_val[j] != '\0')
	{
		res[j] = temp_val[j];
		j++;
	}
	if (temp[i])
	{
		while (temp[i] != '\0')
			res[j++] = temp[i++];
	}
	res[j] = '\0';
	free(temp_val);
	return (res);
}

void	replace_dollar_sign(char *str, t_env **env, t_mini_shell *ms)
{
	int		i;
	char	*temp;

	temp = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (temp == NULL)
		return ;
	i = 0;
	while (str[i] != '\0' && str[i] != '"' && !ft_isspace(str[i])
		&& str[i] != '$')
	{
		if (str[i] == '\'' && (!ft_isalnum(str[i + 1]) && str[i + 1] != '?'))
			break ;
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	if (temp[0] == '\0')
		ms->env_value = ft_strdup("$");
	else if (ft_strncmp(temp, "?", 1) == 0)
		ms->env_value = ft_ret_val(temp, ms);
	else
		ms->env_value = get_env_value(temp, *env);
	free(temp);
}

void	quotes_out(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_str_increased(char *str, int *i, t_mini_shell **ms, int *j)
{
	if (j != NULL)
		(*j) += ft_strlen((*ms)->env_value);
	if (str[(*i)] == '$')
		(*i)++;
	while (str[(*i)] && !ft_isspace(str[(*i)]) && str[(*i)] != '"'
		&& str[(*i)] != '$')
	{
		(*i)++;
		if (str[(*i)] == '\'' && !ft_isalnum(str[(*i) + 1]))
			break ;
	}
	free((*ms)->env_value);
}
