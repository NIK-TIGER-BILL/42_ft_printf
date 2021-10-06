/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalsami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:47:36 by ebalsami          #+#    #+#             */
/*   Updated: 2021/06/01 17:47:38 by ebalsami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# include "../libft/libft.h"

typedef struct s_all
{
	struct		s_flag
	{
		char		minus;
		char		plus;
		char		grid;
		char		space;
		char		null;
	}			flags;
	int			width;
	int			precision;
	char		type;
	char		char_null;
	enum
	{
		none,
		h,
		hh,
		l,
		ll
	}				e_length;
}			t_all;

typedef struct s_float_flags
{
	int			precision;
	intmax_t	exponent;
	char		null;
	char		minus;
	char		dot;
	int			len_str;

}				t_float_flags;

// good ft
int				ft_printf(const char *format, ...);
const char		*ft_parse_specification(t_all *all,
					const char *str, va_list *ap);
int				ft_isset(int c, const char *set);

// do ft
char			*ft_do_type(t_all *all, va_list *ap);
char			*t_do_c_or_procent(t_all *all, va_list *ap);
char			*ft_do_di(t_all *all, va_list *ap);
char			*ft_do_ouxX(t_all *all, va_list *ap);
char			*ft_do_s(va_list *ap);
char			*ft_do_p(t_all *all, va_list *ap);

// help ft
int				ft_isset(int c, const char *set);
int				ft_putchar(char c);
int				ft_write_str(t_all *all, char *str);
int				ft_putstr(char *str);
unsigned int	ft_putnbr(int n);
char			*ft_strupper(char *str);
char			*ft_itoa_base(uintmax_t n, unsigned int base,
					 const char *alphabet);
char			*ft_llitoa(intmax_t n);

// help flags ft
char			*ft_str_concatenate(char *s1, char *s2);
char			*ft_str_add_separator(char *s, char separator,
					int count, int side);
char			*ft_str_crop(char *s, int n);

// flags ft
char			*ft_do_plus(char *str);
char			*ft_do_space(char *str);
char			*ft_do_grid(char *str, t_all *all);
char			*ft_do_width(char *str, t_all *all);
char			*ft_do_precision(char *str, t_all *all);

#endif
