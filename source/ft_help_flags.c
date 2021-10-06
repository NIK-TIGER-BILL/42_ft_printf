/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:14:18 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 20:14:19 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_str_concatenate(char *s1, char *s2)
{
	char	*result;
	char	*tmp;

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (0);
	tmp = result;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	return (result);
}

void	ft_str_add_separator_2(char *s, char *result, int n, char
separator)
{
	int	side;

	side = 0;
	if (n < 0)
	{
		n = -n;
		side = 1;
	}
	if (*result == '-')
		result++;
	if (!side)
		while (n--)
			*result++ = separator;
	while (*s)
		*result++ = *s++;
	if (side)
		while (n--)
			*result++ = separator;
	*result = 0;
}

char	*ft_str_add_separator(char *s, char separator, int count, int side)
{
	char	*result;
	int		n;

	n = count - ft_strlen(s);
	if (n <= 0)
		return (s);
	result = malloc((count + 1) * sizeof(char));
	if (!result)
	{
		free(s);
		return (0);
	}
	result[0] = ' ';
	if (separator == '0' && !side && *s == '-')
	{
		*s = separator;
		*result = '-';
		n--;
	}
	if (side == 1)
		n = -n;
	ft_str_add_separator_2(s, result, n, separator);
	free(s);
	return (result);
}

char	*ft_str_crop(char *s, int n)
{
	int		i;
	char	*result;

	if (n > ft_strlen(s))
		return (s);
	result = malloc((n + 1) * sizeof(char));
	if (!result)
	{
		free(s);
		return (0);
	}
	i = -1;
	while (++i < n)
		result[i] = s[i];
	result[i] = 0;
	free(s);
	return (result);
}
