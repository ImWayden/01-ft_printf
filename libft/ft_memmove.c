/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:07:22 by therodri          #+#    #+#             */
/*   Updated: 2022/11/12 19:27:17 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (char *)dest;
	psrc = (char *)src;
	if (pdest < psrc)
		while (n-- > 0)
			*(pdest++) = *(psrc++);
	else
		while (n-- > 0)
			pdest[n] = psrc[n];
	return (dest);
}
