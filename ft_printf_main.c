/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:44:39 by eperperi          #+#    #+#             */
/*   Updated: 2024/03/23 14:04:47 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (input[i] != '%')
		{
			if (write(1, &input[i], 1) < 0)
				return (-1);
			counter++;
		}
		else
		{
			i++;
			print_cases(input, args, i, &counter);
		}
		i++;
	}
	va_end(args);
	return (counter);
}

int	print_cases(const char *input, va_list args, int i, int *counter)
{
	if (input[i] == 'd' || input[i] == 'i')
		print_num(va_arg(args, int), counter);
	else if (input[i] == 'u')
		print_unum(va_arg(args, unsigned int), counter);
	else if (input[i] == 'c')
		print_char(va_arg(args, int), counter);
	else if (input[i] == 's')
		putstr(va_arg(args, char *), counter);
	else if (input[i] == 'p')
		p_calc((unsigned long)va_arg(args, void *), counter);
	else if (input[i] == 'x')
		hex_calc(va_arg(args, unsigned int), counter, 'x');
	else if (input[i] == 'X')
		hex_calc(va_arg(args, int), counter, 'X');
	else if (input[i] == '%')
		print_char(input[i], counter);
	return (1);
}
