/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_uoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 18:12:27 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 11:52:52 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_u(int *okjs, char *d, char *res, char *widt)
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

intmax_t	ft_atoi_f(const char *str)
{
	int			sing;
	intmax_t	res;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	res = 0;
	sing = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sing = -1;
		else
			sing = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sing);
}

char		*ft_itoa_f(intmax_t n)
{
	intmax_t	num;
	char		*str;
	int			i;

	num = n;
	i = 0;
	if (n < 0)
		i = 1;
	while ((n > 9 || n < -9) && ++i)
		n /= 10;
	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (str[i] != '-' && i >= 0)
	{
		str[i--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}
