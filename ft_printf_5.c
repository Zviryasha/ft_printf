/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 16:17:13 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/30 17:02:10 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*faceless(char *res, int *okjs, char *widt, char *d)
{
	okjs[3] = (int)ft_strlen(res);
	okjs[2] = ft_atoi(widt);
	if (okjs[1] < okjs[2] && okjs[0] < okjs[2])
	{
		if (!(is_minus(d)))
			res = width1(res, widt);
		else
			res = width(res, widt);
	}
	if (is_null(d))
		null(res);
	return (res);
}

char	*ft_itoa_for_printf_2(long long int n)
{
	long long int	num;
	char			*str;
	int				i;

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

int		checko(char c)
{
	int		i;
	char	*s;

	s = "QWRTYIPAGHJKLZVBNMqwrygkvbnm{}[]";
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || c == '\n' || c == '\0')
			return (0);
		i++;
	}
	return (1);
}

char	*calc(char *tr, int j, int i)
{
	char	*r;
	int		p;

	p = 0;
	r = ft_strnew(i + 1);
	r[i] = '\0';
	while (i > 0)
	{
		r[p] = tr[j - i];
		p++;
		i--;
	}
	return (r);
}

int		check_negoo(char *tr, int *k, int *a)
{
	int		j;

	j = *k;
	(j)++;
	while (check(tr[j]) == 1 && checko(tr[j]) == 1)
		j++;
	if (checko(tr[j]) == 0)
		return (0);
	if (check(tr[j]) == 0)
		return (1);
	return (1);
}
