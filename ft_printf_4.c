/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 15:46:02 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:49:18 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*major_1(char *res, int *okjs, uintmax_t i, char *d)
{
	char *p;

	if (res == NULL || !(okjs[0]))
	{
		res = ft_itoa_for_printf_2(i);
		okjs[5] = 1;
	}
	if ((i - 1) == 9223372036854775807)
	{
		res = ft_strnew(21);
		p = "-9223372036854775808";
		res = ft_strcpy(res, p);
		okjs[5] = 1;
	}
	if (i == 0 && is_dot(d) && no_pres(d))
	{
		res = ft_strnew(1);
		p = "";
		res = ft_strcpy(res, p);
		okjs[5] = 1;
	}
	return (res);
}

int		hexio(char c, long long int i, char *d, int *a)
{
	char	*pres;
	char	*widt;
	char	*res;
	int		okjs[4];

	check_type_xx(d, c, &i);
	res = short_x(c, res, i, d);
	olo(d, okjs, res);
	pres = ft_strnew(okjs[0] + 1);
	widt = ft_strnew(okjs[2] + 1);
	next2(okjs, pres, widt, d);
	if (is_star(d))
	{
		starix(okjs, a);
		pres = ft_itoa(okjs[0]);
		widt = ft_itoa(okjs[2]);
	}
	if (okjs[1] < ft_atoi(pres))
		res = precision_olo(pres, res);
	okjs[0] = ft_atoi(pres);
	res = faceless(res, okjs, widt, d);
	if (is_hash(d))
		res = heshio(res, c, okjs, d);
	ft_putstr(res);
	return ((int)ft_strlen(res));
}

int		what_type(va_list arg, char c, char *d, int *a)
{
	uintmax_t i;

	if (c == 'd' || c == 'D' || c == 'i')
	{
		i = va_arg(arg, long long int);
		a[2] = next(d, i, c, a);
	}
	else if (c == 'c' || c == 'C')
	{
		i = va_arg(arg, int);
		chario(d, i, a);
	}
	else if (c == 'o' || c == 'O')
	{
		i = va_arg(arg, unsigned long long int);
		a[2] = onion(d, i, a, c);
	}
	else if (c == 'x' || c == 'X')
	{
		i = va_arg(arg, uintmax_t);
		a[2] = hexio(c, i, d, a);
	}
	else
		a[2] = what_type2(arg, c, d, a);
	return (a[2]);
}

void	star(char *d, int *k, va_list arg)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	k[1] = 0;
	k[0] = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '.' && d[i + 1] == '*')
		{
			k[0] = va_arg(arg, int);
			i = i + 2;
		}
		if (d[i] == '*')
			k[1] = va_arg(arg, int);
		i++;
	}
}

char	*ft_itoa_for_printf(unsigned long long int n)
{
	unsigned long long int	num;
	char					*str;
	int						i;

	num = n;
	i = 0;
	while ((n > 9) && ++i)
		n /= 10;
	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	while (str[i] != '-' && i >= 0)
	{
		str[i--] = '0' + num % 10;
		num /= 10;
	}
	return (str);
}
