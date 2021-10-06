/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_ouxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:45:28 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:45:29 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static uintmax_t	ft_get_unnum_modifier(t_all *all, va_list *ap)
{
	uintmax_t	num;

	num = va_arg(*ap, uintmax_t);
	if (all->e_length == none)
		return ((unsigned int)num);
	else if (all->e_length == hh)
		return ((unsigned char)num);
	else if (all->e_length == h)
		return ((unsigned short int)num);
	else if (all->e_length == l)
		return ((unsigned long int )num);
	else if (all->e_length == ll)
		return ((unsigned long long int)num);
	else
		return (0);
}

char	*ft_do_ouxX(t_all *all, va_list *ap)
{
	char		*str;
	int			base;
	uintmax_t	nb;

	nb = ft_get_unnum_modifier(all, ap);
	if (all->type == 'o')
		base = 8;
	else if (all->type == 'u')
		base = 10;
	else
		base = 16;
	str = ft_itoa_base(nb, base, "0123456789abcdef");
	if (all->type == 'X')
		str = ft_strupper(str);
	return (str);
}
