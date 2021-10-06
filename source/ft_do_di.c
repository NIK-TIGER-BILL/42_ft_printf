/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:44:54 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:44:55 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t	ft_get_num_modifier(t_all *all, va_list *ap)
{
	intmax_t	num;

	num = va_arg(*ap, intmax_t);
	if (all->e_length == none)
		return ((int)num);
	else if (all->e_length == hh)
		return ((char)num);
	else if (all->e_length == h)
		return ((short int)num);
	else if (all->e_length == l)
		return ((long int )num);
	else if (all->e_length == ll)
		return ((long long int)num);
	else
		return (0);
}

char	*ft_do_di(t_all *all, va_list *ap)
{
	char		*str;
	intmax_t	nb;

	nb = ft_get_num_modifier(all, ap);
	str = ft_llitoa(nb);
	return (str);
}
