/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:51:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/08 23:18:44 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function name    | ft_putstr
// Prototype        | int ft_putstr(char *s);
// Parameters       | s: The string to output.
// Return value     | Number of chars written
// External functs. | write
// Description      | Outputs the string ’s’ to the stdout.
//
// Change log:
// 2022/06/08 Adapted to fit the behaviour of printf with NULL string
int	ft_putstr(char *s)
{
	size_t	printed;

	printed = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s != '\0')
		printed += ft_putchar(*s++);
	return (printed);
}
