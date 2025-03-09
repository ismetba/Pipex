/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:53:19 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 15:55:20 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, int *total_length);

void	ft_putstr(char *str, int *total_length)
{
	while (*str)
	{
		ft_putchar(*str, total_length);
		str++;
	}
}
