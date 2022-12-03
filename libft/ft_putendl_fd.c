/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 04:27:24 by therodri          #+#    #+#             */
/*   Updated: 2022/11/09 21:08:28 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Écrit La chaîne de caractères ’s’ sur le
descripteur de fichier donné suivie d’un retour à
la ligne.
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
	write(fd, "\n", 1);
}
