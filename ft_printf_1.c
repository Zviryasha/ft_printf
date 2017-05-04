/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 13:15:26 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/01 14:48:24 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check(char c)
{
	int		i;
	char	*s;

	s = "sSpdDioOuUxXcC%";
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*stry(char *tr, int *j)
{
	int		k;
	char	*d;

	d = ft_strnew(50);
	k = 0;
	(*j)++;
	while (check(tr[(*j)]) == 1)
	{
		d[k] = tr[(*j)];
		k++;
		(*j)++;
	}
	d[k] = '\0';
	return (d);
}

int		chario(char *d, int i, int *a)
{
	char	*pres;
	char	*widt;
	char	*res;
	int		okjs[4];

	res = ft_strnew(2);
	res = shock(d, res, okjs, i);
	pres = ft_strnew(okjs[0] + 1);
	widt = ft_strnew(okjs[2] + 1);
	next2(okjs, pres, widt, d);
	if (is_star(d))
	{
		starix(okjs, a);
		pres = ft_itoa(okjs[0]);
		widt = ft_itoa(okjs[2]);
	}
	okjs[2] = ft_atoi(widt);
	okjs[0] = ft_atoi(pres);
	free(pres);
	res = manta(okjs, d, res, widt);
	a[2] = print_c(d, res, i, okjs);
	if (a[2] == 0 && i == 0)
		a[2]++;
	return (a[2]);
}

void	olo(char *d, int *okjs, char *res)
{
	okjs[0] = check_precision(d);
	okjs[2] = check_width(d);
	okjs[1] = ft_strlen(res);
}

char	*shock(char *d, char *res, int *okjs, int i)
{
	res[1] = '\0';
	res[0] = (char)i;
	okjs[0] = check_precision(d);
	okjs[2] = check_width(d);
	return (res);
}
