/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:32:18 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/27 17:54:14 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type_j(char *d)
{
	int i;

	i = 0;
	while (d[i] != 0)
	{
		if (d[i] == 'j')
			return (1);
		i++;
	}
	return (0);
}

int		check_type_z(char *d)
{
	int i;

	i = 0;
	while (d[i] != 0)
	{
		if (d[i] == 'z')
			return (1);
		i++;
	}
	return (0);
}

int		check1(char c)
{
	int		i;
	char	*s;

	s = "U";
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}
