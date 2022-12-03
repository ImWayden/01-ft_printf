/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:49:55 by therodri          #+#    #+#             */
/*   Updated: 2022/11/12 03:05:54 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Alloue (avec malloc(3)) et retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaîne de
caractères.
*/
#include "libft.h"
#include <stdio.h>
/*include strchr*/
static int	ft_bool_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (1);
	if (c == 0)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1);
	if (!set[0])
		return (ft_strdup(s1));
	while (s1[i] && ft_bool_strchr(set, s1[i]))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (ft_bool_strchr(set, s1[--j]))
		;
	return ((char *)ft_substr(s1, i, j + 1 - i));
}
