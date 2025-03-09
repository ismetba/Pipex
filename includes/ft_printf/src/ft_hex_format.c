/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:29 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 16:00:54 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunbr_base(unsigned int nbr, char *base, int *total_length);

void	ft_hex_format(char c, int *total_length, unsigned int u_converted)
{
	if (c == 'x')
		ft_putunbr_base(u_converted, "0123456789abcdef", total_length);
	else
		ft_putunbr_base(u_converted, "0123456789ABCDEF", total_length);
}
