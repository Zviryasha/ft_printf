/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:15:09 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/03 17:41:55 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(uintmax_t n, int base, char *d)
{
	char			*t;
	uintmax_t		div;
	char			temp;
	int				i;

	i = 0;
	t = ft_strnew(24);
	div = base;
	if (n == 0)
		return (t = yong(d, t));
	while (n / div >= base)
		div *= base;
	if (n < 16)
	{
		t[i] = yong_1(n, div, temp, base);
		return (t);
	}
	while (div > 0)
	{
		t[i] = yong_2(&n, &div, &temp, base);
		i++;
	}
	t[23] = '\0';
	return (t);
}

char	*ft_itoa_base_2(uintmax_t n, int base, char *d)
{
	char			*t;
	uintmax_t		div;
	char			temp;
	int				i;

	i = 0;
	t = ft_strnew(24);
	div = base;
	if (n == 0)
		return (yong(d, t));
	while (n / div >= base)
		div *= base;
	if (n < 16)
	{
		t[i] = yong_4(n, div, temp, base);
		return (t);
	}
	while (div > 0)
	{
		t[i] = yong_3(&n, &div, &temp, base);
		i++;
	}
	t[23] = '\0';
	return (t);
}

char	*yong(char *d, char *t)
{
	if (is_dot(d) && no_pres(d))
	{
		t = ft_strnew(1);
		t[0] = '\0';
	}
	else
	{
		t = ft_strnew(2);
		t[0] = '0';
		t[1] = '\0';
	}
	return (t);
}

char	yong_1(uintmax_t n, uintmax_t div, char temp, int base)
{
	n %= div;
	div /= base;
	temp = '0' + n / div;
	if (temp > '9')
		temp += 7;
	return (temp);
}
