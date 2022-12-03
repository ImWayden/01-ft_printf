/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 04:27:34 by therodri          #+#    #+#             */
/*   Updated: 2022/12/03 13:21:55 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
	ft_print_sign
		imprime les signes en fonctions des flags presents et des valeurs 
		 des different arguments
		puis remplis de 0 tant que la valeur de precison n'est pas nulle
		ou si le flags 0 est trouve sans precison alors ce sera jusqu'a
		 la valeur du field min 
*/
void	ft_print_sign(t_args *args, int *total_count, MEM arguments)
{
	if (args->type == 's')
		return ;
	if ((args->type == 'i' || args->type == 'd') && args->flags[7])
		*total_count += write(1, "-", 1);
	if ((args->type == 'i' || args->type == 'd') && args->flags[5]
		&& !args->flags[7])
		*total_count += write(1, " ", 1);
	if ((args->type == 'i' || args->type == 'd') && args->flags[3]
		&& !args->flags[7])
		*total_count += write(1, "+", 1);
	if (args->type == 'X' && args->flags[4] && arguments != 0)
		*total_count += write(1, "0X", 2);
	if (((args->flags[4] && args->type == 'x') || args->type == 'p')
		&& arguments != 0)
		*total_count += write(1, "0x", 2);
	args->n[1]++;
	while (--args->n[1] > 0)
		*total_count += write(1, "0", 1);
	++args->n[0];
	while (--args->n[0] > 0 && args->flags[0])
		*total_count += write(1, "0", 1);
}

/*
ft_putnbr_base
	print un nombre en base 10 ou 16 en focntion de du converteur
	trouve precedement
*/
void	ft_putnbr_base_f(MEM n, t_args *args, int *total_count)
{
	if (args->type == 'p' && args->flags[7])
	{
		*total_count += write(1, "(nil)", 5);
		return ;
	}
	if (n > args->t_base - 1)
	{
		ft_putnbr_base_f(n / args->t_base, args, total_count);
		ft_putnbr_base_f(n % args->t_base, args, total_count);
	}
	else if (n < args->t_base)
		*total_count += write(1, &args->base[n], 1);
}

/*
	ft_putstr_f
	fait quasi la meme chose que sa version count a la difference
	qu'il imprime plutot que de compter les caractere
	de plus il s'arretera si jamais il y a une precision non null 
	et inferieur a 6(la taille necessaire pour ecrire (null)) car 
	il n'aura rien a imprimer.	
*/
void	ft_putstr_f(MEM va_args, t_args *args, int *total_count)
{
	char	*str;
	int		c;
	int		n;

	n = 0;
	if (args->type == '%')
		*total_count += write(1, "%", 1);
	else if (args->type == 'c')
	{
		c = (char)va_args;
		*total_count += write(1, &c, 1);
	}
	else
	{
		str = (char *)va_args;
		if (str == NULL)
		{
			if (args->n[1] < 6 && args->n[1] != 0)
				return ;
			str = "(null)";
		}
		while (str[n] && (n < args->n[1] || !args->flags[2]))
			*total_count += write(1, &str[n++], 1);
	}
}

/*
	ft_print
	lance seulement les deux autre fonction sauf si l'argument est == 0
	et la precision null fonctionne bien uniaquement parceque le flag precision
	ne fonctionne pas avec les pointeur;
*/
void	ft_print(MEM arguments, t_args *args, int *total_count)
{
	if (args->pre_z && arguments == 0)
		return ;
	if (args->conv > 1)
		ft_putnbr_base_f(arguments, args, total_count);
	else
		ft_putstr_f(arguments, args, total_count);
}
