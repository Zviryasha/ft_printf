/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:00:43 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:37:58 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_minus(char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int		is_plus(char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

char	*plus(char *s, int sing)
{
	int		i;
	char	*t;
	int		k;
	char	c;

	i = 0;
	c = '+';
	k = ft_strlen(s);
	t = ft_strnew(k + 2);
	t[k + 1] = '\0';
	if (sing == -1)
		return (s);
	t[0] = c;
	i++;
	while (i < k + 1)
	{
		t[i] = s[i - 1];
		i++;
	}
	t[i] = s[i - 1];
	free(s);
	return (t);
}

int		is_null(char *d)
{
	int i;

	i = 0;
	while (d[i] != '\0' && !(d[i] > '0' && d[i] <= '9'))
	{
		if (d[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

void	null(char *s)
{
	int i;
	int sing;

	sing = 0;
	i = 0;
	if (s[i] == '0' && s[i + 1] == 'x')
		i = i + 2;
	while ((s[i] == ' ' || s[i] == '-' || s[i] == '+') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			sing = -1;
		if (s[i] == '+')
			sing = 1;
		s[i] = '0';
		i++;
	}
	if (sing)
	{
		if (sing == -1)
			s[0] = '-';
		else
			s[0] = '+';
	}
}
