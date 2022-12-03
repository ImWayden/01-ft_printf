/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:02:09 by therodri          #+#    #+#             */
/*   Updated: 2022/11/12 19:26:52 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (char *)dest;
	psrc = (char *)src;
	while (n-- > 0)
		*(pdest++) = *(psrc++);
	return (dest);
}
