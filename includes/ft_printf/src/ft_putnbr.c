/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:53:14 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 15:55:15 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, int *total_length);

void	ft_putnbr(int n, int *total_length)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', total_length);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, total_length);
		ft_putchar((nbr % 10) + '0', total_length);
	}
	else
		ft_putchar(nbr + '0', total_length);
}
