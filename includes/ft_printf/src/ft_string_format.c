/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:53:27 by ibayandu          #+#    #+#             */
/*   Updated: 2025/02/25 20:51:47 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, int *total_length);
void	ft_putstr(char *str, int *total_length);

void	ft_string_format(va_list args, int *total_length, int x)
{
	char	*string_ptr;
	int		strlen;

	*total_length = *total_length - (x);
	string_ptr = va_arg(args, char *);
	if (string_ptr == NULL)
	{
		ft_putstr("(null)", total_length);
		return ;
	}
	strlen = ft_strlen(string_ptr);
	while (x > strlen && x > 0)
	{
		x = x - 1;
		ft_putchar(' ', total_length);
	}
	if (string_ptr != NULL)
		ft_putstr(string_ptr, total_length);
	while (-x > strlen && x < 0)
	{
		x++;
		ft_putchar(' ', total_length);
	}
}
