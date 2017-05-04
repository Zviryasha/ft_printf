/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:27:55 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/27 17:51:05 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type_idd(char *d, char c, long long int *i)
{
	if (c == 'i' || c == 'd')
	{
		if (check_type_ll(d))
			(*i) = (long long int)(*i);
		else if (check_type_l(d))
			(*i) = (long int)(*i);
		else if (check_type_hh(d))
			(*i) = (signed char)(*i);
		else if (check_type_h(d))
			(*i) = (short int)(*i);
		else if (check_type_j(d))
			(*i) = (intmax_t)(*i);
		else if (check_type_z(d))
			(*i) = (size_t)(*i);
		else
			(*i) = (int)(*i);
	}
	else if (c == 'D')
		(*i) = (intmax_t)(*i);
}

void	check_type_ocu(char *d, char c, unsigned long long int *i)
{
	if (c == 'u')
	{
		if (check_type_ll(d))
			(*i) = (unsigned long long int)(*i);
		else if (check_type_l(d))
			(*i) = (unsigned long int)(*i);
		else if (check_type_hh(d))
			(*i) = (unsigned char)(*i);
		else if (check_type_h(d))
			(*i) = (unsigned short int)(*i);
		else if (check_type_j(d))
			(*i) = (uintmax_t)(*i);
		else if (check_type_z(d))
			(*i) = (uintmax_t)(*i);
		else
		{
			(*i) = (unsigned int)(*i);
			if ((*i) > 4294967295)
				(*i) = (*i) - 4294967296;
		}
	}
	else if (c == 'o')
		lolita(d, i);
}

void	check_type_xx(char *d, char c, long long int *i)
{
	if (c == 'x' || c == 'X')
	{
		if (check_type_ll(d))
			(*i) = (unsigned long long int)(*i);
		else if (check_type_l(d))
			(*i) = (unsigned long int)(*i);
		else if (check_type_hh(d))
			(*i) = (unsigned char)(*i);
		else if (check_type_h(d))
			(*i) = (unsigned short int)(*i);
		else if (check_type_j(d))
			(*i) = (uintmax_t)(*i);
		else if (check_type_z(d))
			(*i) = (size_t)(*i);
		else
			(*i) = (unsigned int)(*i);
	}
}

void	lolita(char *d, unsigned long long *i)
{
	if (check_type_ll(d))
		(*i) = (unsigned long long int)(*i);
	else if (check_type_l(d))
		(*i) = (unsigned long int)(*i);
	else if (check_type_hh(d))
		(*i) = (unsigned char)(*i);
	else if (check_type_h(d))
		(*i) = (unsigned short int)(*i);
	else if (check_type_j(d))
		(*i) = (uintmax_t)(*i);
	else if (check_type_z(d))
		(*i) = (size_t)(*i);
	else
	{
		(*i) = (unsigned int)(*i);
	}
}
