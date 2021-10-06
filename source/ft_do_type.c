/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:46:12 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:46:13 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_do_flags(t_all *all, char *str)
{
	if (str && ft_strchr("sdiouxX", all->type) && all->precision >= 0)
		str = ft_do_precision(str, all);
	if (str && ft_strchr("oxX", all->type) && all->flags.grid)
		str = ft_do_grid(str, all);
	if (str && all->width > 0)
		str = ft_do_width(str, all);
	if (str && ft_strchr("di", all->type) && all->flags.plus)
		str = ft_do_plus(str);
	if (str && ft_strchr("di", all->type) && all->flags.space)
		str = ft_do_space(str);
	return (str);
}

char	*ft_do_type(t_all *all, va_list *ap)
{
	char	*str;

	if (ft_strchr("c%", all->type))
		str = t_do_c_or_procent(all, ap);
	else if (all->type == 's')
		str = ft_do_s(ap);
	else if (ft_strchr("di", all->type))
		str = ft_do_di(all, ap);
	else if (ft_strchr("ouxX", all->type))
		str = ft_do_ouxX(all, ap);
	else if (all->type == 'p')
		str = ft_do_p(all, ap);
	else
		return (0);
	if (str)
		str = ft_do_flags(all, str);
	return (str);
}
