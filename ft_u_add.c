/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvaladar <pvaladar@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:34:25 by pvaladar          #+#    #+#             */
/*   Updated: 2022/06/08 16:37:43 by pvaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_add(uintptr_t n, char *base)
{
	uintptr_t	temp;
	uintptr_t	printed;

    printed = 0;
	//if (n < 0)
	//	printed += ft_u_add(n, base);
	temp = n;
	if (n >= (uintptr_t)ft_strlen(base))
	{
		printed += ft_u_add(n / ft_strlen(base), base);
		printed += ft_u_add(n % ft_strlen(base), base);
	}
	else
		printed += ft_putchar(base[n % ft_strlen(base)]);
	return (printed);
}
