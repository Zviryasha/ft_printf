/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_uoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:12:27 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:50:53 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_u(int *okjs, char *d, char *res, char *widt)
{
	int p;

	if (okjs[1] < okjs[2] && okjs[0] < okjs[2])
	{
		if (!(is_minus(d)))
			res = width1(res, widt);
		else
			res = width(res, widt);
	}
	if (is_null(d))
		null(res);
	ft_putstr(res);
	p = (int)(ft_strlen(res));
	free(d);
	free(widt);
	free(res);
	return (p);
}
