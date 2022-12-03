/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:39:13 by therodri          #+#    #+#             */
/*   Updated: 2022/11/12 04:51:18 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_s;
	unsigned int	dest_s;

	src_s = 0;
	dest_s = 0;
	while (src[src_s])
		src_s++;
	if (size == 0)
		return (src_s);
	while (dest[dest_s] && dest_s < size)
		dest_s++;
	if (size <= dest_s)
		return (size + src_s);
	i = 0;
	while (src[i] && (dest_s + i) < size - 1)
	{
		dest[dest_s + i] = src[i];
		i++;
	}
	dest[dest_s + i] = '\0';
	return (dest_s + src_s);
}
