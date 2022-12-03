/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 04:16:25 by therodri          #+#    #+#             */
/*   Updated: 2022/11/16 22:10:23 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères passée en argument pour créer
une nouvelle chaîne de caractères (avec malloc(3))
résultant des applications successives de ’f’.
*/
#include "libft.h"
/*include strdup*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*cpy;

	cpy = ft_strdup((char *)s);
	if (!cpy)
		return (NULL);
	i = -1;
	while (s[++i])
		cpy[i] = f(i, s[i]);
	return (cpy);
}
