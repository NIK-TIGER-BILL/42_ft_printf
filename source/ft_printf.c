/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:46:55 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:46:56 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;
	t_all	all;
	char	*str;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_parse_specification(&all, ++format, &ap);
			str = ft_do_type(&all, &ap);
			if (!str)
				return (-1);
			count += ft_write_str(&all, str);
			free(str);
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(ap);
	return (count);
}
