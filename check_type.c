/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sashaka1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:20:19 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/27 17:26:06 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type_ll(char *d)
{
	int i;

	i = 0;
	while (d[i + 1] != 0)
	{
		if (d[i] == 'l' && d[i + 1] == 'l')
			return (1);
		i++;
	}
	return (0);
}

int		check_type_l(char *d)
{
	int i;

	i = 0;
	while (d[i] != 0)
	{
		if (d[i] == 'l')
			return (1);
		i++;
	}
	return (0);
}

int		check_type_hh(char *d)
{
	int i;

	i = 0;
	while (d[i + 1] != 0)
	{
		if (d[i] == 'h' && d[i + 1] == 'h')
			return (1);
		i++;
	}
	return (0);
}

int		check_type_h(char *d)
{
	int i;

	i = 0;
	while (d[i] != 0)
	{
		if (d[i] == 'h')
			return (1);
		i++;
	}
	return (0);
}
