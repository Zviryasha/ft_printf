/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:47:38 by opanchen          #+#    #+#             */
/*   Updated: 2017/05/04 10:43:25 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(char *d, char *res, int i, int *okjs)
{
	int p;

	if (is_null(d))
		null(res);
	if (i == 0)
	{
		if (okjs[4] < 0)
		{
			p = 1;
			ft_putchar('\0');
			while (res[p] != '\0')
			{
				ft_putchar(res[p]);
				p++;
			}
		}
		else
			upita(res);
	}
	else
		ft_putstr(res);
	p = (int)ft_strlen(res);
	free(res);
	free(d);
	return (p);
}

void	upita(char *res)
{
	int p;

	p = 0;
	while (res[p + 1] != '\0')
	{
		ft_putchar(res[p]);
		p++;
	}
	ft_putchar('\0');
}
