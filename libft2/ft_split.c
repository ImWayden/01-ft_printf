/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:59:17 by therodri          #+#    #+#             */
/*   Updated: 2022/11/13 00:43:35 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Alloue (avec malloc(3)) et retourne un tableau
de chaînes de caractères obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL.
*/
#include "libft.h"
#include <stdio.h>
/*include strdup*/

static void	*freetab(char **tab, int i)
{
	while (tab[i] != NULL && i >= 0)
	{
		free(tab[i]);
		tab[i] = NULL;
		i--;
	}
	free(tab[i]);
	free(tab);
	tab = NULL;
	return (NULL);
}

static int	nb_word(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_str_to_tab(char *str, char c, char **res)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (j < nb_word(str, c))
	{
		k = 0;
		while (str[i] == c)
			i++;
		i--;
		while (str[++i] != c && str[i])
			k++;
		if (k)
		{
			res[j] = ft_substr(str, i - k, k);
			if (!res[j])
				return (freetab(res, j));
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		count;

	count = nb_word((char *)str, c);
	res = (char **)ft_calloc(sizeof(char *), count + 1);
	if (!res || !str)
		return (NULL);
	if (str[0] == 0 && c == 0)
	{
		res[0] = NULL;
		return (res);
	}	
	res[count] = NULL;
	if (!ft_str_to_tab((char *)str, c, res))
		return (freetab(res, count - 1));
	return (res);
}
/*
int	main(void)
{
	int		i;
	char	**res;
	char	c;
	char	*argv;

	argv = ft_strdup("      split       this for   me  !       ");
	c = '-';
	i = -1;
	res = ft_split(argv, ' ');
	while (++i <= nb_word(argv, c))
		printf("res[%d] = %s\n", i, res[i]);
	free(argv);
	freetab(res);
	return (0);
}
*/