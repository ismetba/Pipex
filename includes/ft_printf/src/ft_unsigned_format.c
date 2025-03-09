/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:53:31 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 16:01:08 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, int *total_length);
void	ft_putunbr_base(unsigned int nbr, char *base, int *total_length);

void	ft_unsigned_format(va_list args, int *total_length)
{
	unsigned int	u_converted;

	u_converted = va_arg(args, unsigned int);
	if (u_converted == 0)
		ft_putchar('0', total_length);
	else
		ft_putunbr_base(u_converted, "0123456789", total_length);
}
