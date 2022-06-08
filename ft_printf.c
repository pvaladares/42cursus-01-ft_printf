/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:03:24 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/08 16:40:40 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
// ...
// DESCRIPTION
//     The printf() family of functions produces output according to a format as
//     described below.  The printf() function writes output to stdout, the 
//     standard output stream;
// ...
//     These functions write the output under the control of a format string 
//     that specifies how subsequent arguments (or arguments accessed via the 
//     variable-length argument facilities of stdarg(3)) are converted 
//     for output.
// ...
// RETURN VALUES
//     Function returns the number of characters printed (not including
//     the trailing `\0' used to end output to strings).
//     Functions returns a negative value if an error occurs.
//
// ------
//
// Variadic Function uses the following, based on STDARG(3):
// - va_list  : type to hold the information about variable arguments
// - va_start : initialize the variable argument list name given
// - va_arg   : retrieve the next argument
// - va_end   : end the argument list 
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;
	int		i;

	if (format == NULL)
		return (0);
	va_start(args, format);
	printed = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			printed += format_parser(format[i + 1], args);
			i++;
		}
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}

// Function takes the format after the '%' and redirects to the relevant
// functon to handle the argument
//
// Format as per subject
// - %c Prints a single character.
// - %s Prints a string (as defined by the common C convention).
// - %p The void * pointer argument has to be printed in hexadecimal format.
// - %d Prints a decimal (base 10) number.
// - %i Prints an integer in base 10.
// - %u Prints an unsigned decimal (base 10) number.
// - %x Prints a number in hexadecimal (base 16) lowercase format.
// - %X Prints a number in hexadecimal (base 16) uppercase format.
// - %% Prints a percent sign.
/*
	######### NOT WORKING #######
	- %p
	- %s with NULL
	- unsigned %x %X %u
*/
int	format_parser(char format, va_list args)
{
	int		printed;

	printed = 0;
	if (format == 'c')
		printed += ft_putchar(va_arg(args, int));
	else if (format == 's')
		printed += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		printed += ft_putstr("0x");
		printed += ft_u_putnbr_base(va_arg(args, uintptr_t), BASE16LOWER);
		//printed += ft_u_add(va_arg(args, uintptr_t), BASE16LOWER);
	}
	else if (format == 'd' || format == 'i')
		printed += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		printed += ft_u_putnbr_base(va_arg(args, uintptr_t), BASE10);
	else if (format == 'x')
		printed += ft_u_putnbr_base(va_arg(args, unsigned int), BASE16LOWER);
	else if (format == 'X')
		printed += ft_u_putnbr_base(va_arg(args, unsigned int), BASE16UPPER);
	else if (format == '%')
		printed += ft_putchar('%');
	return (printed);
}

/*
25:     TEST(1, print(" %p ", -1));
30:     TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
31:     TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
*/
/*
int	main(void)
{
	int	i;
	int	j;
	int	k;
	char	*ptr;
	char	c;

	c = '0';
	ptr = NULL;
	k = 666;
	//ptr = &k;
	i = ft_printf("ft_printf : [%p] ", -1);
	printf("Printed [%d]\n", i);
	j =    printf("   printf : [%p] ", -1);
	printf("Printed [%d]\n", j);
	return (0);
}
*/