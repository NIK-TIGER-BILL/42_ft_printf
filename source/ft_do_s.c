/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:46:04 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:46:05 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_do_s(va_list *ap)
{
	char	*s;
	char	*str;

	s = va_arg(*ap, char *);
	if (s == 0)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	return (str);
}
