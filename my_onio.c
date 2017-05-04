/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_onio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:00:55 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:50:17 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_o(int *okjs, char *d, char *res, char *widt)
{
	int p;

	if (okjs[3] < okjs[2] && okjs[0] < okjs[2])
	{
		if (!(is_minus(d)))
			res = width1(res, widt);
		else
			res = width(res, widt);
	}
	if (is_null(d))
		null(res);
	if (is_hash(d))
		res = hash_o(res, okjs, d);
	ft_putstr(res);
	p = (int)ft_strlen(res);
	free(widt);
	free(d);
	if (!(is_dot(d) && no_pres(d) || res[0] == '0'))
		free(res);
	return (p);
}
