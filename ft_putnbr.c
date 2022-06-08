/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:13:20 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/08 16:15:01 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function name    | ft_putnbr
// Prototype        | int ft_putnbr_fd(int n);
// Parameters       | n: The integer to output.
// Return value     | Number of chars written
// External functs. | write
// Description      | Outputs the integer ’n’ to the stdout.
//
// INT_MIN = -2147483648
// Note: In this implementation a static variable is usedd to keep the
// balance of total chars already printed between recursive calls to the 
// function; The static variable concept was learnt from Get Next Line project
int	ft_putnbr(int n)
{
	size_t					printed;
	unsigned long long int	number;

	printed = 0;
	number = n;
	if (n < 0)
	{
		number = -number;
		printed += ft_putchar('-');
	}
	if (number >= 10)
	{
		printed += ft_putnbr(number / 10);
		printed += ft_putnbr(number % 10);
	}
	else
		printed += ft_putchar(number + '0');
	return (printed);
}
