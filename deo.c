/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 10:40:42 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:37:21 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		din(int *okjs, char *res, char *d, char *widt)
{
	int p;

	if (is_plus(d))
		res = plus(res, okjs[3]);
	if (okjs[1] < okjs[2] && okjs[0] < okjs[2])
	{
		if (!(is_minus(d)) || okjs[4] == -1)
			res = width1(res, widt);
		else
			res = width(res, widt);
	}
	if (is_null(d) && !okjs[0])
		null(res);
	if (is_space(d))
		res = space(res, okjs);
	ft_putstr(res);
	p = (int)ft_strlen(res);
	free(d);
	free(widt);
	free(res);
	return (p);
}
