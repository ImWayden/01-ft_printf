/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:44:44 by therodri          #+#    #+#             */
/*   Updated: 2022/11/11 22:34:50 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Renvoie le dernier élément de la liste.
*/
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
