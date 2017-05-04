/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 17:28:23 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/30 18:40:58 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ursa(char *tr, int *j, int *k, char *s)
{
	int i;

	i = 0;
	if (tr[*j] == '-' || tr[*j] == '+')
	{
		if (tr[*j] == '-')
			k[1] = 1;
		(*j)++;
	}
	if (tr[*j] == '0')
	{
		k[0] = 1;
		(*j)++;
	}
	while (tr[*j] >= '0' && tr[*j] <= '9')
	{
		s[i] = tr[*j];
		(*j)++;
		i++;
	}
	return (s);
}

int		streyf(char *s, char *res, int *k, char c)
{
	if (s[0])
	{
		if (k[1])
			res = width1(res, s);
		else
			res = width(res, s);
	}
	if (k[0])
		null(res);
	ft_putstr(res);
	if (!c)
		return ((int)ft_strlen(res));
	else
		return ((int)ft_strlen(res) + 1);
}

void	lifestil(char *tr, int j, int *i)
{
	ft_putchar(tr[j]);
	i[2]++;
	if (tr[j] == '\0')
		ft_putchar('\0');
}
