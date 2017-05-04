/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:39:00 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 11:57:21 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		big_c(wchar_t u, char *d, int *a)
{
	unsigned int	i[2];
	char			*s;
	unsigned int	mask[4];
	unsigned char	octet;

	mask[1] = 14712960;
	mask[0] = 49280;
	mask[2] = 4034953344;
	i[0] = (unsigned int)u;
	s = ft_itoa_base(i[0], 2, d);
	i[1] = ft_strlen(s);
	if (i[1] <= 7)
		a[2] = first_c(u, i[0], octet);
	else if (i[1] <= 11)
		a[2] = se(u, i[0], mask[0], octet);
	else if (i[1] <= 16)
		a[2] = third_c(u, i[0], mask[1], octet);
	else
		a[2] = fo(u, i[0], mask[2], octet);
	free(s);
	return (a[2]);
}

int		first_c(wchar_t u, unsigned int i, unsigned char o)
{
	o = u;
	write(1, &o, 1);
	return (1);
}

int		se(wchar_t u, unsigned int i, unsigned int mask1, unsigned char o)
{
	unsigned char o2;
	unsigned char o1;

	o2 = (i << 26) >> 26;
	o1 = ((i >> 6) << 27) >> 27;
	o = (mask1 >> 8) | o1;
	write(1, &o, 1);
	o = ((mask1 << 24) >> 24) | o2;
	write(1, &o, 1);
	return (2);
}

int		third_c(wchar_t u, unsigned int i, unsigned int mask2, unsigned char o)
{
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o3 = (i << 26) >> 26;
	o2 = ((i >> 6) << 26) >> 26;
	o1 = ((i >> 12) << 28) >> 28;
	o = (mask2 >> 16) | o1;
	write(1, &o, 1);
	o = ((mask2 << 16) >> 24) | o2;
	write(1, &o, 1);
	o = ((mask2 << 24) >> 24) | o3;
	write(1, &o, 1);
	return (3);
}

int		fo(wchar_t u, unsigned int i, unsigned int mask3, unsigned char o)
{
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o4 = (i << 26) >> 26;
	o3 = ((i >> 6) << 26) >> 26;
	o2 = ((i >> 12) << 26) >> 26;
	o1 = ((i >> 18) << 29) >> 29;
	o = (mask3 >> 24) | o1;
	write(1, &o, 1);
	o = ((mask3 << 8) >> 24) | o2;
	write(1, &o, 1);
	o = ((mask3 << 16) >> 24) | o3;
	write(1, &o, 1);
	o = ((mask3 << 24) >> 24) | o4;
	write(1, &o, 1);
	return (4);
}
