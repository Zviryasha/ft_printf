/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hesh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 12:32:23 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:44:20 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_hash(char *d)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '#')
			count++;
		i++;
	}
	return (count);
}

char	*pussy(char *s, int i, char c)
{
	char	*t;
	int		k;
	int		j;

	j = 2;
	k = (int)ft_strlen(s);
	t = (char *)malloc(sizeof(char) * (k + 1 + i));
	t[k + i] = '\0';
	t[0] = '0';
	t[1] = c;
	while (s[j - i] != '\0')
	{
		t[j] = s[j - i];
		j++;
	}
	return (t);
}

char	*hash(char *s, int i, char c)
{
	char	*t;

	t = NULL;
	if (is_spa(s))
		return (s);
	if (i == 0)
		t = pussy(s, 2, c);
	else if (i == 1)
		t = pussy(s, 1, c);
	else if (i == 2)
		t = pussy(s, 2, c);
	return (t);
}

char	*toto(char *s, char c)
{
	int		j;
	char	*t;
	int		p;

	j = 0;
	kekos(s, &j);
	if (s[j] == '0')
	{
		if (j <= 2)
		{
			t = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2 + (2 - j)));
			t[ft_strlen(s) + (2 - j)] = '\0';
			p = (int)ft_strlen(s) + (1 - j);
		}
		else
			tortilia_1(t, &p, s);
		lolets(s, t, p);
		fol(j, s, t, c);
		return (t);
	}
	else if (s[j] != '0' && s[j] != '\0')
		s = horos(t, s, j, c);
	return (s);
}

void	lolets(char *s, char *t, int p)
{
	int k;

	k = ft_strlen(s) - 1;
	while (k >= 0)
	{
		t[p] = s[k];
		k--;
		p--;
	}
}
