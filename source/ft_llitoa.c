/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:46:39 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:46:40 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_numlen(intmax_t num, int minus)
{
	int	i;

	i = 1;
	num /= 10;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i + minus);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_llitoa(intmax_t n)
{
	char	*p;
	int		len;
	int		minus;

	minus = 0;
	if (n < 0)
		minus = 1;
	len = ft_numlen(n, minus);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	p[len] = 0;
	while (--len >= minus)
	{
		p[len] = (char)(ft_abs((int)(n % 10)) + '0');
		n /= 10;
	}
	if (minus)
		p[0] = '-';
	return (p);
}
