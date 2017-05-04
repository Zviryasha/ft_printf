/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_olo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:24:19 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/27 18:41:10 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_olo(char *s, char *t)
{
	char	*p;
	int		i;
	int		k;

	k = ft_atoi(s);
	i = 0;
	p = ft_strnew(k + 1);
	p[k] = '\0';
	while (i < k)
	{
		p[i] = '0';
		i++;
	}
	i = ft_strlen(t);
	while (i >= 0)
	{
		p[k] = t[i];
		i--;
		k--;
	}
	if (s[1] != '\0' && s[2] != '\0')
		free(s);
	return (p);
}

char	*short_x(char c, char *res, long long int i, char *d)
{
	if (c == 'X')
		res = ft_itoa_base(i, 16, d);
	else if (c == 'x')
		res = ft_itoa_base_2(i, 16, d);
	return (res);
}
