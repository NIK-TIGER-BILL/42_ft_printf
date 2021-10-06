/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:47:05 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:47:06 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	if (!c)
		return (0);
	write(1, &c, 1);
	return (1);
}

int	ft_write_str(t_all *all, char *str)
{
	int	i;

	i = 0;
	if (all->char_null && all->flags.minus)
		i += (int)write(1, "\0", 1);
	i += ft_putstr(str);
	if (all->char_null && !all->flags.minus)
		i += (int)write(1, "\0", 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-(unsigned int)n);
	return ((unsigned int)n);
}

unsigned int	ft_putnbr(int n)
{
	unsigned int	num;
	unsigned int	count;

	count = 0;
	if (n < 0)
		count += ft_putchar('-');
	num = ft_abs(n);
	if (num >= 10)
	{
		count += ft_putnbr((int)(num / 10));
		count += ft_putnbr((int)(num % 10));
	}
	else
		count += ft_putchar((char)(num % 10 + '0'));
	return (count);
}
