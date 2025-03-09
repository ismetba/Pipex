/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:38 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 15:59:32 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, int *total_length);
void	ft_putnbr(int nbr, int *total_length);

void	ft_integer_format(int *total_length, int i_converted)
{
	if (i_converted == 0)
		ft_putchar('0', total_length);
	else
		ft_putnbr(i_converted, total_length);
}
