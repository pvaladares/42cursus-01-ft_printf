/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:03:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/03/30 17:58:32 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PRINTF(3)               BSD Library Functions Manual               PRINTF(3)
//
// NAME
//      printf -- formatted output conversion
//
// LIBRARY
//      Standard C Library (libc, -lc)
//
// SYNOPSIS
//      #include <stdio.h>
//
//      int
//      printf(const char * restrict format, ...);

// va_list  : type to hold the information about variable arguments
// va_start : initialize the variable argument list name given
// va_arg   : retrieve the next argument
// va_end   : end the argument list

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	ft_putchar('a');
	// va_list	args;
	return puts(format);
	// va_start(args, format);
	// puts(args);
	// va_end(args);
}

int	main(void)
{
	ft_printf("Hello World");
	return (0);
}
