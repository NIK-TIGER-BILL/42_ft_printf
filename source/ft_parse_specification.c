/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specification.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:46:47 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:46:47 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_init_all(t_all *all)
{
	all->flags.minus = 0;
	all->flags.grid = 0;
	all->flags.null = 0;
	all->flags.plus = 0;
	all->flags.space = 0;
	all->width = 0;
	all->precision = -1;
	all->type = 0;
	all->e_length = none;
	all->char_null = 0;
}

static const char	*ft_check_flags(t_all *all, const char *str)
{
	while (ft_isset(*str, "-0+# "))
	{
		if (*str == '-')
			all->flags.minus = 1;
		else if (*str == '+')
			all->flags.plus = 1;
		else if (*str == '0')
			all->flags.null = 1;
		else if (*str == ' ')
			all->flags.space = 1;
		else if (*str == '#')
			all->flags.grid = 1;
		str++;
	}
	if (all->flags.space == 1 && all->flags.plus == 1)
		all->flags.space = 0;
	if (all->flags.null == 1 && all->flags.minus == 1)
		all->flags.null = 0;
	return (str);
}

static const char	*ft_check_precision_or_width(int *result,
											   const char *str, va_list *ap)
{
	*result = 0;
	if (*str == '*')
	{
		*result = va_arg(*ap, int);
		str++;
	}
	else if (*str >= '0' && *str <= '9')
	{
		*result = ft_atoi(str);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	return (str);
}

static const char	*ft_check_modifier(t_all *all, const char *str)
{
	if (*str == 'h' || *str == 'l')
	{
		if (*str == 'h')
			all->e_length = h;
		else if (*str == 'l')
			all->e_length = l;
		str++;
		if (*str == 'h' || *str == 'l')
		{
			if (*str == 'h')
				all->e_length = hh;
			else if (*str == 'l')
				all->e_length = ll;
			str++;
		}
	}
	return (str);
}

const char	*ft_parse_specification(t_all *all, const char *str, va_list *ap)
{
	ft_init_all(all);
	str = ft_check_flags(all, str);
	str = ft_check_precision_or_width(&all->width, str, ap);
	if (all->width < 0)
	{
		all->flags.minus = 1;
		if (all->flags.null == 1)
			all->flags.null = 0;
		all->width = -all->width;
	}
	if (*str == '.')
		str = ft_check_precision_or_width(&all->precision, ++str, ap);
	str = ft_check_modifier(all, str);
	all->type = *str++;
	return (str);
}
