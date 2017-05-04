/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:28:19 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:53:18 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_star(char *d)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '*')
			c++;
		i++;
	}
	return (c);
}

void	starix(int *okjs, int *a)
{
	if (a[0] != 0)
	{
		okjs[0] = a[0];
		if (okjs[0] < 0)
		{
			okjs[0] = 0;
			okjs[5] = 1;
		}
	}
	if (a[1] != 0)
	{
		okjs[2] = a[1];
		if (okjs[2] < 0)
		{
			okjs[2] = -okjs[2];
			okjs[4] = -1;
		}
	}
}

void	starix_s(int *okjs, int *a, char *res)
{
	if (a[0] != 0)
	{
		okjs[0] = a[0];
		if (okjs[0] < 0)
		{
			okjs[0] = (int)ft_strlen(res);
		}
	}
	if (a[1] != 0)
	{
		okjs[2] = a[1];
		if (okjs[2] < 0)
		{
			okjs[2] = -okjs[2];
			okjs[4] = -1;
		}
	}
}
