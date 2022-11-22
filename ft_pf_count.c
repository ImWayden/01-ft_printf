/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 04:42:58 by therodri          #+#    #+#             */
/*   Updated: 2022/11/22 02:26:44 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ft_sign_field 
	fonction qui replis plusieurs role essentiels
	vas remettre le flags 0 a nul si une precision est presente
	sort de la function si l'arg vaut 0 et la precision est nul car rien ne 
	doit etre print si ce n'est le field min
	reduit la taille du field min en fonction des signe qu'il devra imprimer
	set les valeur des base et leur string correspondante pour pouvoir
	utiliser putnbr_base_c et f juste apres
*/
void	ft_sign_field(t_args *args, MEM arguments)
{
	if (args->flags[0] && args->flags[2])
		args->flags[0] = 0;
	if (args->pre_z && arguments == 0)
		return ;
	if ((args->flags[3] || args->flags[6]) && !args->flags[7])
		args->n[0] -= 1;
	if (args->flags[4] || ((args->type == 'x' || args->type == 'X')
			&& args->flags[4]))
		args->n[0] -= 2;
	if (args->type == 'd' || args->type == 'i' || args->type == 'u')
	{
		args->base = TEN;
		args->t_base = 10;
	}
	if (args->type == 'x' || args->type == 'X' || args->type == 'p')
		args->t_base = 16;
	if (args->type == 'X')
		args->base = BEX;
	if (args->type == 'x' || args->type == 'p')
		args->base = HEX;
}

/*
	ft_putnbr_base_c
	c pour count agit de la meme maniere que ft_putnbr_base sauf 
	que ca compte les caractere qui vont etre imprimee 
		plutot que de les imprimer de suite
	flags[6] permet d'empecher de compter plusieur fois le caractere negatif
	en recurence
*/
void	ft_putnbr_base_c(MEM n, t_args *args)
{
	if ((args->type == 'd' || args->type == 'i') && args->flags[7]
		&& !args->flags[6])
	{
		args->n[0]--;
		args->flags[6]++;
	}
	if (args->type == 'p' && args->flags[7])
	{
		args->count += 5;
		return ;
	}
	else if (n > args->t_base - 1)
	{
		ft_putnbr_base_c(n / args->t_base, args);
		ft_putnbr_base_c(n % args->t_base, args);
	}
	else if (n < args->t_base)
	{
		args->count++;
	}
}

/*
ft_putstr_c
	meme principe que putstr a la difference que ca gere les caractere simple
	si jamais l'argument est null str deviendra la chaine de caractere nul
	et sera compter comme tel, la grosse difference avec putstr de base
	se trouve dans la conditon du while qui s'arretera si jamais la str 
	est plus longue que la precison si jamais le flag correspondant est present
*/
void	ft_putstr_c(MEM va_args, t_args *args)
{
	char	*str;
	int		n;

	n = 0;
	if (args->type == 'c')
		args->n[0]--;
	else
	{
		str = (char *)va_args;
		if (str == NULL)
		{
			if (args->n[1] < 6)
				args->n[1] = 0;
			str = "(null)";
		}
		while (str[n] && (n < args->n[1] || !args->flags[2]))
		{
			n++;
		}
		args->count = n;
	}
}

/*
	ft_count_hub 
	fonction un peu degeu qui permet de lancer les deux fonction de comptage
	puis vas modifier la taille du field en fonction de la precison afin de
	ne pas avoir de caractere en trop lors de l'impression c'est la seule 
	si jamais il n'y a pas de flag precision ou que la presion est nul 
	alors seul le field min sera modifier
 */
void	ft_count_hub(MEM arguments, t_args *args)
{
	if (args->conv > 1)
		ft_putnbr_base_c(arguments, args);
	else
		ft_putstr_c(arguments, args);
	if (args->n[1] > args->count && args->type != 's')
		args->n[0] -= args->n[1];
	else
		args->n[0] -= args->count;
	if (args->type != 's')
		args->n[1] -= args->count;
}
