/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_o_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:34:34 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/27 17:16:24 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	yong_2(uintmax_t *n, uintmax_t *div, char *temp, int base)
{
	*temp = '0' + (*n) / (*div);
	if (*temp > '9')
		*temp += 7;
	(*n) %= (*div);
	(*div) /= base;
	return (*temp);
}

char	yong_3(uintmax_t *n, uintmax_t *div, char *temp, int base)
{
	*temp = '0' + (*n) / (*div);
	if (*temp > '9')
		*temp += 39;
	(*n) %= (*div);
	(*div) /= base;
	return (*temp);
}

char	yong_4(uintmax_t n, uintmax_t div, char temp, int base)
{
	n %= div;
	div /= base;
	temp = '0' + n / div;
	if (temp > '9')
		temp += 39;
	return (temp);
}
