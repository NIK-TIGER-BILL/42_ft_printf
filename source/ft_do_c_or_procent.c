/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_c_or_procent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:44:48 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:44:49 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*t_do_c_or_procent(t_all *all, va_list *ap)
{
	char	*str;
	char	c;

	if (all->type == '%')
	{
		all->precision = -1;
		c = '%';
	}
	else if (all->type == 'c')
		c = (char)va_arg(*ap, int);
	else
		return (0);
	str = malloc(2 * sizeof(char));
	if (!str)
		return (0);
	*(str + 1) = 0;
	if (!c)
	{
		all->char_null = 1;
		if (all->width > 0)
			all->width--;
	}
	*str = c;
	return (str);
}
