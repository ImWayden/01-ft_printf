/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:06:13 by therodri          #+#    #+#             */
/*   Updated: 2022/11/13 00:39:53 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Alloue (avec malloc(3)) et renvoie un nouvel
	élément. La variable membre ’content’ est
	initialisée à l’aide de la valeur du paramètre
	’content’. La variable ’next’ est initialisée à
	NULL.
*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
