/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:02:10 by therodri          #+#    #+#             */
/*   Updated: 2022/12/03 13:21:45 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
Init la struct qui contiendra toute les infomartion relative aux flags
 a la taille de la base utilisee etc.. de l'argument actuel
args->conv numero corespondant a un converteur (cspdiuxX)
args->n[0] field min
args->n[1] precision
args->flags tableau de booleen permettant de savoir si tel ou tel flags 
	est present 0 = Zero 1 = MOINS  2 = POINT 3 = PLUS 4 = DIEZ 5 = SPACE
	7 = NEG ou pointeur NULL
args->type contient la lettre de la balise de l'arg actuel
args->i permet sauter les flags lors de la lecture de la str 
	principale afin d'en eviter l'ecriture
args->pre_z bool qui permet de savoir si il y a une precison suivi d'un zero
*/
void	ft_init_struct(t_args *args)
{
	args->conv = -1;
	args->n[0] = 0;
	args->n[1] = 0;
	args->flags[0] = 0;
	args->flags[1] = 0;
	args->flags[2] = 0;
	args->flags[3] = 0;
	args->flags[4] = 0;
	args->flags[5] = 0;
	args->flags[6] = 0;
	args->flags[7] = 0;
	args->flags[8] = 0;
	args->flags[9] = 0;
	args->count = 0;
	args->type = 0;
	args->t_base = 0;
	args->i = 0;
	args->pre_z = 0;
}

/*
ft_init_bal est appeler par ft_printf en boucle a chaque % rencontre
	il permet de naviguer dans la balise changer la valeur des booleen des flags
	pour ce faire il boucle jusqu'a tomber sur un converteur
	il atoi des qu'il croise un chiffre qui n'est pas zero et le stock dans n[0]
		ce sera la taille min du field
	s'il tombe sur un point il tentera de atoi a partir du caractere suivant
	s'il y parvient le nombre sera stocke dans args->n[1] et representera 
	la precision, s'il echoue alors om icremente args-pre_z 
		pour indiquer une pre null
*/
void	ft_init_bal(const char *str, t_args *args)
{
	int	i;
	int	j;

	i = -1;
	while (ft_strchr_index(CONVERT, str[++i]) == 9)
	{
		j = ft_strchr_index(FLAGS, str[i]);
		if ((!args->flags[j] && j != 0) || (j == 0 && args->n[0] <= 0))
			args->flags[j] = i + 1;
		if (ft_isdigit(str[i]) && args->n[0] <= 0 && str[i] != '0'
			&& args->flags[2] == 0)
			args->n[0] = ft_atoi(&str[i]);
		if (args->flags[2] > 0 && args->n[1] == 0)
			args->n[1] = ft_atoi(&str[i + 1]);
		if (!args->n[1] && args->flags[2] > 0)
			args->pre_z++;
	}
	args->i = i + 1;
	args->type = str[i];
	args->conv = ft_strchr_index(CONVERT, str[i]);
}

/*
	ft_init_args
	recupere les arguments dans le type correspondant a la balise
	puis check si le pointeur est nul ou si l'entier est negatif et renvois 
	tout en unsigned long long int (defined MEM) 
	parceque c'est la taille la plus grande et ca permet de tout stocker 
	de l'adresse de pointeur au int simple afin de pouvoir de le recast plus tard
	si besoin ou simplement tout imprimer
*/
MEM	ft_init_args(va_list argslist, t_args *args, int *total_count)
{
	if (args->type == 'd' || args->type == 'i' || args->type == 'c')
		return (ft_abs(va_arg(argslist, int), args));
	else if (args->type == 's')
		return ((MEM)va_arg(argslist, char *));
	else if (args->type == 'u' || args->type == 'x' || args->type == 'X')
		return ((MEM)va_arg(argslist, unsigned int));
	else if (args->type == 'p')
		return (ft_check_null(va_arg(argslist, MEM), args));
	else
		*total_count += write(1, "%", 1);
	return (0);
}

/*
	ft_convert_hub 
	fonction depuis laquel vont etre lancee les fonctions 
	permettant de calculer la taille des different fields
	puis si le flags - n'est pas present imprimer le marging
	ensuite lancer les fonction pour print les champs sign et number
	et si le flags - est present imprimer le marging
*/
void	ft_convert_hub(MEM arguments, t_args *args, int *total_count)
{
	ft_sign_field(args, arguments);
	ft_count_hub(arguments, args);
	if (!args->flags[1])
	{
		while (args->n[0] > 0 && !args->flags[0])
		{
			*total_count += write(1, " ", 1);
			args->n[0]--;
		}
	}
	ft_print_sign(args, total_count, arguments);
	ft_print(arguments, args, total_count);
	if (args->flags[1])
	{
		while (args->n[0] > 0)
		{
			if (args->flags[0])
				*total_count += write(1, "0", 1);
			else
				*total_count += write(1, " ", 1);
			args->n[0]--;
		}
	}
}

/*
	ft_printf
	fonction depuis laquelle tout le reste vas etre lancee, la 
	declaration de deux struct(celle qui vas etre init dans ft_init_struct)
	dont l'une d'elle ne sert qu'a economiser 2 lignes
	le concept est simple on avance dans str de base soit on croise une balise 
	et on lance l'initialisation de la struct des flags de l'argument
	si jamais l'on est pas sur une balise % 
		on lance la fonction convert hub qui lancera la suite
	si jamais on ne croise pas de balise on imprime simplement 
		les caractere que l'on croise
	au final on renvois total count qui correspond au nombre de caractere 
	ayant ete ecrit
*/
int	ft_printf(char const *str, ...)
{
	va_list	argslist;
	t_args	args;
	t_var	_;

	_.i = -1;
	_.total_count = 0;
	ft_init_struct(&args);
	va_start(argslist, str);
	while (++_.i < ft_strlen(str))
	{
		if (str[_.i] == '%')
		{
			ft_init_struct(&args);
			ft_init_bal(&str[_.i + 1], &args);
			_.i += args.i;
			_.va_args = ft_init_args(argslist, &args, &_.total_count);
			if (args.type != '%')
				ft_convert_hub(_.va_args, &args, &_.total_count);
		}
		else
			_.total_count += write(1, &str[_.i], 1);
	}
	va_end(argslist);
	return (_.total_count);
}
