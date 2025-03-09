/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:47 by ibayandu          #+#    #+#             */
/*   Updated: 2025/01/05 16:03:01 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putchar(char c, int *total_length);
void		ft_putstr(char *str, int *total_length);
void		ft_string_format(va_list args, int *total_length, int space, int x);
void		ft_integer_format(int *total_length, int i_converted);
void		ft_hex_format(char c, int *total_length, unsigned int u_converted);
void		ft_router(va_list va, const char *str, int *total_length);
void		ft_init_zero(int *x, int *y);

void	ft_bonus_dash(va_list va, const char *str, int *total_length)
{
	unsigned int	u_converted;

	u_converted = va_arg(va, unsigned int);
	if (u_converted == 0)
	{
		ft_putchar('0', total_length);
		return ;
	}
	if (*(str - 1) == '#')
	{
		if (*str == 'x')
			ft_putstr("0x", total_length);
		if (*str == 'X')
			ft_putstr("0X", total_length);
		ft_hex_format(*str, total_length, u_converted);
	}
	else
		ft_hex_format(*str, total_length, u_converted);
}

static void	ft_bonus_integers(va_list va, int *total_length, int plus,
		int space)
{
	int	i_converted;

	i_converted = va_arg(va, int);
	if (i_converted >= 0)
	{
		if (plus == 1)
			ft_putchar('+', total_length);
		else if (plus == 0 && space == 1)
			ft_putchar(' ', total_length);
	}
	ft_integer_format(total_length, i_converted);
}

static void	ft_flag_skip(const char *str, int *plus, int *space, int *index)
{
	while (*str == '#' || *str == ' ' || *str == '+')
	{
		if (*str == '+')
			*plus = 1;
		if (*str == ' ')
			*space = 1;
		str++;
		*index += 1;
	}
}

static void	ft_format(va_list va, const char *str, int *total_length,
		int *index)
{
	int	space;
	int	plus;
	int	number_of_flag;

	ft_init_zero(&space, &plus);
	ft_flag_skip(str, &plus, &space, index);
	str = str + *index;
	number_of_flag = ft_atoi(str);
	*total_length += ft_atoi(str);
	if (*str == '-')
	{
		*index += 1;
		str++;
	}
	while (ft_isdigit(*(str++)))
		*index += 1;
	str--;
	if (*str == 'c')
		ft_putchar(va_arg(va, int), total_length);
	else if (*str == 's')
		ft_string_format(va, total_length, space, number_of_flag);
	else if (*str == 'i' || *str == 'd')
		ft_bonus_integers(va, total_length, plus, space);
	else
		ft_router(va, str, total_length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_length;
	int		index;

	va_start(args, str);
	total_length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			index = 0;
			ft_format(args, str, &total_length, &index);
			str = str + index;
		}
		else
			ft_putchar(*str, &total_length);
		str++;
	}
	va_end(args);
	return (total_length);
}
