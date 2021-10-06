/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:46:28 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:46:29 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_numlen(uintmax_t num, unsigned int base)
{
	int	i;

	i = 1;
	num /= base;
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

char	*ft_itoa_base(uintmax_t n, unsigned int base, const char *alphabet)
{
	char	*p;
	int		len;

	len = ft_numlen(n, base);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	p[len] = 0;
	while (--len >= 0)
	{
		p[len] = alphabet[n % base];
		n /= base;
	}
	return (p);
}
