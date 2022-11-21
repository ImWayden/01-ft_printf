/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:15:11 by therodri          #+#    #+#             */
/*   Updated: 2022/11/08 22:42:03 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = 0;
	while (s[n])
		n++;
	if (c == 0)
		return ((char *)s + n);
	while (n-- > 0)
		if (s[n] == (char)c)
			return ((char *)(&s[n]));
	return (NULL);
}
