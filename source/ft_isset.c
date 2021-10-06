/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:46:20 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:46:21 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isset(int c, const char *set)
{
	while (*set)
	{
		if ((unsigned char)c == *set)
			return (1);
		set++;
	}
	return (0);
}
