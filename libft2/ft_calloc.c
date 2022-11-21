/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:21:34 by therodri          #+#    #+#             */
/*   Updated: 2022/11/19 22:47:26 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 The calloc() function allocates memory for an array 
 of nmemb elements of size bytes each and 
 returns a pointer to the allocated memory.
*/
#include "libft.h"
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		true_size;

	true_size = nmemb * size;
	if (nmemb && true_size / nmemb != size)
		return (NULL);
	ptr = malloc(true_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, true_size);
	return (ptr);
}
