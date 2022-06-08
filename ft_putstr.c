/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:51:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/08 16:30:12 by pvaladar         ###   ########.fr       */
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
	int		ret;

	printed = 0;
	ret = 0;
	if (s == NULL)
		return (ft_putstr("(null)"));
	while (*s != '\0')
	{
		ret = write(1, s++, 1);
		if (ret == -1)
			return (ret);
		printed += ret;
	}
	return (printed);
}
