/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:01:05 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/08 23:28:36 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BASE10
#  define BASE10 "0123456789"
# endif

# ifndef BASE16LOWER
#  define BASE16LOWER "0123456789abcdef"
# endif

# ifndef BASE16UPPER
#  define BASE16UPPER "0123456789ABCDEF"
# endif

//# include "Libft/libft.h"
# include <unistd.h> // required by write
# include <stdarg.h> // required by `variable argument lists`, see STDARG(3)
# include <stdlib.h>
# include <stdio.h> // FOR TESTS ONLY
# include <limits.h> // For Tests
# include <errno.h>

// ft_printf.c
int		ft_printf(const char *format, ...);
int		format_parser(char format, va_list args);

// Single files *.c
int		ft_putchar(char c);
int		ft_putnbr_base(int n, char *base);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_u_putnbr_base(unsigned int n, char *base);
int		ft_u_add(uintptr_t n, char *base);

#endif
