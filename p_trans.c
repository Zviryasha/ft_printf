/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_trans.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 16:11:19 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/01 14:45:46 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pipi(void *s, char *d, int *a)
{
	int					okjs[4];
	char				*pres;
	char				*widt;
	unsigned long int	n;

	n = (unsigned long int)s;
	okjs[0] = check_precision(d);
	okjs[2] = check_width(d);
	okjs[3] = tirion(okjs, n, d);
	if (okjs[3] == 0)
	{
		pres = ft_strnew(okjs[0] + 1);
		widt = ft_strnew(okjs[2] + 1);
		next2(okjs, pres, widt, d);
		okjs[2] = ft_atoi(widt);
		okjs[0] = ft_atoi(pres);
		d = p_1(d);
		okjs[1] = hexio('x', n, d, a);
		return (okjs[1]);
	}
	else
		return (okjs[3]);
}

char	*p_1(char *d)
{
	char *t;

	t = ft_strnew(ft_strlen(d) + 5);
	t = ft_strcpy(t, d);
	t[ft_strlen(d)] = '#';
	t[ft_strlen(d) + 1] = 'l';
	t[ft_strlen(d) + 2] = 'l';
	free(d);
	return (t);
}

int		tirion(int *okjs, unsigned long int n, char *d)
{
	char *pres;

	if (is_dot(d) && no_pres(d) && n == 0)
	{
		pres = ft_strnew(3);
		pres[0] = '0';
		pres[1] = 'x';
		pres[2] = '\0';
		ft_putstr(pres);
		free(pres);
		return (2);
	}
	else if (n == 0 && !okjs[0] && !okjs[2])
	{
		pres = ft_strnew(4);
		pres[0] = '0';
		pres[1] = 'x';
		pres[2] = '0';
		pres[3] = '\0';
		ft_putstr(pres);
		free(pres);
		return (3);
	}
	return (0);
}
