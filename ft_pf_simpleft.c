/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_simpleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 03:28:42 by therodri          #+#    #+#             */
/*   Updated: 2022/11/22 02:40:34 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_strchr_index(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (i);
	return (9);
}

MEM	ft_check_null(MEM n, t_args *args)
{
	if (args->type == 'p' && n == 0)
		args->flags[7] = 1;
	else if (args->type == 'p' && n != 0)
		args->n[0] -= 2;
	return (n);
}

MEM	ft_abs(long int argslist, t_args *args)
{
	if (argslist < 0 && args->type != 'c')
	{
		args->flags[7] = 1;
		return (argslist *= -1);
	}
	return (argslist);
}

int	ft_star(const char *str, va_list star, t_args *args)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '*')
	{
		j = va_arg(star, int);
		if (j >= 0)
			return (j);
		else if (j < 0)
		{
			args->flags[1]++;
			return (j * -1);
		}
	}
	else if ((ft_isdigit(str[i]) || str[i] == '*') && args->n[0] <= 0
		&& str[i] != '0' && args->flags[2] == 0)
		return (ft_atoi(&str[i]));
	else if (args->flags[2] > 0 && args->n[1] == 0)
		return (ft_atoi(&str[i + 1]));
}
