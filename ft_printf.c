/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:12:45 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/01 14:24:42 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	char		*tr;
	int			i[10];
	int			j;
	va_list		arg;

	j = 0;
	va_start(arg, format);
	tr = format;
	i[2] = 0;
	while (tr[j] != '\0')
	{
		if (tr[j] != '%')
			lifestil(tr, j, i);
		else if (tr[j] == '%')
		{
			i[9] = i[2];
			if (check_negoo(tr, &j, i))
				i[2] = lolkek(tr, arg, i, &j);
			else
				i[2] = fantom(tr, &j);
		}
		j++;
	}
	va_end(arg);
	return (i[2]);
}

int		check_neg(char *tr, int *k, int *a)
{
	int		j;
	int		i;
	char	*res;
	char	*widt;

	j = *k + 1;
	while (check(tr[j]) == 1 && checko(tr[j]) == 1)
		j++;
	if (checko(tr[j]) == 0)
	{
		i = 1;
		while (tr[(j - i)] >= '0' && tr[(j - i)] <= '9')
			i++;
		i = i - 1;
		if (i > 0)
		{
			res = "";
			widt = calc(tr, j, i);
			res = width(res, widt);
			ft_putstr(res);
		}
		*k = j - 1;
		return (0);
	}
	return (1);
}

int		fantom(char *tr, int *j)
{
	char	*s;
	int		i;
	char	*res;
	int		k[2];

	(*j)++;
	k[0] = 0;
	k[1] = 0;
	i = *j;
	while (checko(tr[i]) == 1)
		i++;
	res = ft_strnew(2);
	res[0] = tr[i];
	if (tr[i] == '\0')
	{
		(*j)--;
		return (0);
	}
	res[1] = '\0';
	s = ft_strnew(50);
	s[49] = '\0';
	s = ursa(tr, j, k, s);
	return (streyf(s, res, k, tr[*j]));
}

int		lolkek(char *tr, va_list arg, int *i, int *j)
{
	char *d;

	d = stry(tr, j);
	if ((is_star(d)))
		star(d, i, arg);
	i[2] = what_type(arg, tr[*j], d, i) + i[9];
	return (i[2]);
}
