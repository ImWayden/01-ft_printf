/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 03:17:20 by therodri          #+#    #+#             */
/*   Updated: 2022/11/11 18:48:07 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Alloue (avec malloc(3)) et retourne une chaîne
de caractères représentant l’entier ’n’ reçu en
argument. Les nombres négatifs doivent être gérés.
*/
#include "libft.h"

char	*ft_itoa_size(unsigned int nb, int size, int s)
{
	char	*str;

	str = ft_calloc(sizeof(char), (size + 2));
	if (!str)
		return (NULL);
	if (s < 0)
		str[0] = '-';
	while (nb > 0)
	{
		str[size--] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				i;
	int				s;
	unsigned int	nb;

	i = -1;
	nb = n;
	s = 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		s = -1;
		nb = n * -1;
		i++;
	}
	while (nb > 0 && ++i > -1)
		nb /= 10;
	return (ft_itoa_size(n * s, i, s));
}
