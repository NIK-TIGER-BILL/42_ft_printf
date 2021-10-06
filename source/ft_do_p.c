/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:45:55 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:45:57 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_do_p(t_all *all, va_list *ap)
{
	all->type = 'x';
	all->flags.grid = 1;
	all->e_length = l;
	return (ft_do_ouxX(all, ap));
}
