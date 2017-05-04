/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:26:49 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/27 18:44:10 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hash_o(char *s, int *okjs, char *d)
{
	int i;
	int t;

	i = 0;
	t = okjs[3] - okjs[2];
	if (t < 0)
		t = -t;
	while (s[i] == ' ')
		i++;
	if (!(is_minus(d)) && t > 0)
		s = hash_min(okjs, s);
	else if (i == 0 && s[i] != '0')
		s = hesh_o(s);
	else
		s = hesh_o_1(s);
	return (s);
}

char	*hesh_o(char *s)
{
	char	*t;
	int		k;

	t = ft_strnew(ft_strlen(s) + 2);
	t[ft_strlen(s) + 1] = '\0';
	k = ft_strlen(s) + 1;
	while (k + 1)
	{
		t[k] = s[k - 1];
		k--;
	}
	t[0] = '0';
	return (t);
}

char	*hesh_o_1(char *s)
{
	char	*t;
	int		k;

	k = 0;
	t = ft_strnew(ft_strlen(s) + 1);
	t[ft_strlen(s) + 1] = '\0';
	t = ft_strcpy(t, s);
	while (t[k] == ' ' && t[k] != '\0')
		k++;
	if (t[k] != '0')
		t[k - 1] = '0';
	return (t);
}

char	*hash_min(int *okjs, char *s)
{
	int		t;
	char	*p;
	int		i;
	int		o;

	i = 0;
	o = ft_strlen(s);
	p = ft_strnew(o + 1);
	p[o] = '\0';
	while (i < (o - 1))
	{
		p[i + 1] = s[i];
		i++;
	}
	p[0] = '0';
	return (p);
}
