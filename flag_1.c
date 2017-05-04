/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:57:28 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:38:45 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_space(char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	*space(char *s, int *okjs)
{
	int		i;
	char	*t;
	int		k;

	if (s[0] == '0' && okjs[0] < ft_strlen(s))
	{
		s[0] = ' ';
		return (s);
	}
	if (s[0] == ' ')
	{
		s[0] = ' ';
		return (s);
	}
	if (s[0] == '-' || s[0] == '+')
		return (s);
	i = 0;
	k = ft_strlen(s);
	t = ft_strnew(k + 2);
	t[k + 1] = '\0';
	t[0] = ' ';
	while (++i <= k + 1)
		t[i] = s[i - 1];
	free(s);
	return (t);
}

int		is_dot(char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		no_pres(char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '.')
		{
			if (d[i + 1] == '0' || d[i + 1] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int		is_spa(char *s)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			k++;
		i++;
	}
	if (k == i)
		return (1);
	else
		return (0);
}
