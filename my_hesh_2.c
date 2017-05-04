/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hesh_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:52:49 by opanchen          #+#    #+#             */
/*   Updated: 2017/04/29 10:48:09 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tortilia_1(char *t, int *p, char *s)
{
	t = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	t[ft_strlen(s)] = '\0';
	(*p) = (int)ft_strlen(s) - 1;
}

void	kekos(char *s, int *j)
{
	while (s[(*j)] == ' ' && s[(*j)] != '\0')
		(*j)++;
}

char	*horos(char *t, char *s, int j, char c)
{
	t = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	t[ft_strlen(s)] = '\0';
	t = ft_strcpy(t, s);
	t[j - 2] = '0';
	t[j - 1] = c;
	return (t);
}
