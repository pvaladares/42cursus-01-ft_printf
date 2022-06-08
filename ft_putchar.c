/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:37:13 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/08 15:36:02 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function name    | ft_putchar
// Prototype        | int ft_putchar(unsigned char c);
// Parameters       | c: The (unsigned) character to output.
// Return value     | Number of chars written
// External functs. | write
// Description      | Outputs the character ’c’ to the stdout.

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
