/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_simpleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 03:28:42 by therodri          #+#    #+#             */
/*   Updated: 2022/11/21 04:43:27 by therodri         ###   ########.fr       */
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
