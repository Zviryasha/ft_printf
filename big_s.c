/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:23:44 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/01 14:31:56 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		big_s(wchar_t *hs, char *d, int *a)
{
	int i;
	int p;

	i = 0;
	p = 0;
	if (hs == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (hs[i] != '\0')
	{
		a[2] = big_c(hs[i], d, a);
		p = a[2] + p;
		i++;
	}
	free(d);
	return (p);
}
