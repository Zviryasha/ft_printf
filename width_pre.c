/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_pre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:19:13 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 11:32:15 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_width(char *d)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (d[i] != '\0' && !(d[i] > '0' && d[i] <= '9') && d[i] != '.')
		i++;
	if (d[i] >= '0' && d[i] <= '9')
	{
		while (d[i] >= '0' && d[i] <= '9')
		{
			i++;
			j++;
		}
	}
	return (j);
}

void	check_width1(char *d, int o, char *p)
{
	int j;
	int k;

	j = 0;
	k = 0;
	p[o] = '\0';
	while (d[k] != '\0' && !(d[k] > '0' && d[k] <= '9'))
		k++;
	if (d[k] >= '0' && d[k] <= '9')
	{
		while (d[k] >= '0' && d[k] <= '9')
		{
			p[j] = d[k];
			k++;
			j++;
		}
	}
}

char	*precision(char *s, intmax_t u, char *p)
{
	int		i;
	int		k;
	char	*t;

	k = ft_atoi_f(s);
	i = 0;
	if (u < 0)
		k++;
	p = ft_strnew(k + 1);
	p[k] = '\0';
	while (i < k)
	{
		p[i] = '0';
		i++;
	}
	t = ft_itoa_f(u);
	vision(&i, p, t, &k);
	return (p);
}

char	*width(char *s, char *widt)
{
	int		k;
	char	*p;
	int		i;

	i = 0;
	k = ft_atoi(widt);
	p = ft_strnew(k + 1);
	p[k] = '\0';
	while (i < k)
	{
		p[i] = ' ';
		i++;
	}
	i = ft_strlen(s);
	while (i > 0)
	{
		p[k] = s[i];
		i--;
		k--;
	}
	p[k] = s[i];
	return (p);
}

char	*width1(char *s, char *widt)
{
	int		k;
	char	*p;
	int		i;

	i = 0;
	k = ft_atoi(widt);
	p = ft_strnew(k + 1);
	p[k] = '\0';
	while (i < k)
	{
		p[i] = ' ';
		i++;
	}
	k = 0;
	while (s[k] != '\0')
	{
		p[k] = s[k];
		k++;
	}
	if (s[k] != '\0')
		p[k] = s[k];
	return (p);
}
