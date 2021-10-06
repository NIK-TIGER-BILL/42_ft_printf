/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:45:21 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:45:22 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_do_plus(char *str)
{
	char	*result;

	if (*str == '-')
		return (str);
	result = ft_str_concatenate("+", str);
	free(str);
	return (result);
}

char	*ft_do_space(char *str)
{
	char	*result;

	if (*str == '-' || *str == '+')
		return (str);
	result = ft_str_concatenate(" ", str);
	free(str);
	return (result);
}

char	*ft_do_grid(char *str, t_all *all)
{
	char	*result;

	if (all->type == 'o')
		result = ft_str_concatenate("0", str);
	else if (all->type == 'x')
		result = ft_str_concatenate("0x", str);
	else if (all->type == 'X')
		result = ft_str_concatenate("0X", str);
	else
		return (0);
	free(str);
	return (result);
}

char	*ft_do_width(char *str, t_all *all)
{
	char	separator;

	separator = ' ';
	if (all->flags.null && all->precision < 0)
		separator = '0';
	str = ft_str_add_separator(str, separator, all->width, all->flags.minus);
	return (str);
}

char	*ft_do_precision(char *str, t_all *all)
{
	if (all->type == 's')
	{
		if (all->precision == -1)
			return (str);
		str = ft_str_crop(str, all->precision);
	}
	else if (ft_strchr("diouxX", all->type))
	{
		if (*str == '0' && *(str + 1) == 0 && all->precision == 0)
			*str = 0;
		if (*str == '-')
			all->precision++;
		str = ft_str_add_separator(str, '0', all->precision, 0);
	}
	else
		return (0);
	return (str);
}
