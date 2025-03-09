/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:42 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 16:01:37 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr(char *str, int *total_length);
void	ft_putlnbr_base(unsigned long nbr, char *base, int *total_length);

void	ft_pointer_format(va_list args, int *total_length)
{
	unsigned long	u_converted;

	u_converted = va_arg(args, unsigned long);
	if (u_converted == 0)
		ft_putstr("(nil)", total_length);
	else
	{
		ft_putstr("0x", total_length);
		ft_putlnbr_base(u_converted, "0123456789abcdef", total_length);
	}
}
