/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hesh_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:03:29 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:51:41 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*heshio(char *s, char c, int *okjs, char *d)
{
	int i;

	i = 0;
	okjs[3] = okjs[2] - okjs[3];
	if (s[0] == '0' && s[1] == '\0')
		return (s);
	if (!(is_minus(d)) && okjs[3] > 0)
		s = ramus_x(s, okjs);
	else if (okjs[3] > 0)
		s = ramus_xx(s, okjs);
	while (s[i] == ' ')
		i++;
	if (i < 2)
		s = hash(s, i, c);
	else
		s = toto(s, c);
	return (s);
}

void	fol(int j, char *s, char *t, char c)
{
	if (j >= 2)
	{
		if (s[j - 1] == ' ' && s[j - 2] == ' ')
		{
			t[j - 1] = c;
			t[j - 2] = '0';
		}
	}
	else
	{
		t[0] = '0';
		t[1] = c;
	}
}

char	*ramus_x(char *s, int *okjs)
{
	int		i;
	int		o;
	char	*p;

	i = -1;
	o = (int)ft_strlen(s);
	p = ft_strnew(o + 1);
	if (okjs[3] == 1)
	{
		while (++i < (o - 1))
			p[i + 1] = s[i];
		p[0] = ' ';
	}
	else
	{
		while (++i < (o - 2))
			p[i + 2] = s[i];
		p[0] = ' ';
		p[1] = ' ';
	}
	p[o] = '\0';
	return (p);
}

char	*ramus_xx(char *s, int *okjs)
{
	if (okjs[3] == 1)
		s[0] = ' ';
	else
	{
		s[0] = ' ';
		s[1] = ' ';
	}
	return (s);
}
