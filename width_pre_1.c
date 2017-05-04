/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_pre_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 16:27:03 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/29 16:28:03 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_precision(char *d)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (d[i] != '\0' && d[i] != '.')
		i++;
	if (d[i] == '.')
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

void	check_precision1(char *d, int o, char *p)
{
	int j;
	int k;

	j = 0;
	k = 0;
	p[o] = '\0';
	while (d[k] != '\0' && d[k] != '.')
		k++;
	if (d[k] == '.')
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

void	vision(int *i, char *p, char *t, int *k)
{
	(*i) = (int)ft_strlen(t);
	while ((*i) > 0)
	{
		p[*k] = t[*i];
		(*i)--;
		(*k)--;
	}
	if (t[*i] != '-')
		p[*k] = t[*i];
	else
		p[0] = '-';
}
