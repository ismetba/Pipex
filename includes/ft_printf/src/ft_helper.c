/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:23 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 17:43:12 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, int *total_length);
void	ft_unsigned_format(va_list args, int *total_length);
void	ft_pointer_format(va_list args, int *total_length);
void	ft_bonus_dash(va_list va, const char *str, int *total_length);

void	ft_router(va_list va, const char *str, int *total_length)
{
	if (*str == 'p')
		ft_pointer_format(va, total_length);
	else if (*str == 'u')
		ft_unsigned_format(va, total_length);
	else if (*str == 'x' || *str == 'X')
		ft_bonus_dash(va, str, total_length);
	else if (*str == '%')
		ft_putchar('%', total_length);
}

void	ft_init_zero(int *x, int *y)
{
	*x = 0;
	*y = 0;
}
