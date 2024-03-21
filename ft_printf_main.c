/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:44:39 by eperperi          #+#    #+#             */
/*   Updated: 2024/03/21 15:00:42 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	print_cases(char *type, va_list args, int counter, int i);

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		counter;
	char	*type;

	i = 0;
	counter = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			
		}
		i++;
	}
	va_start(args, input);
	print_cases(type, args, counter, 0);
	va_end(args);
}

// int	print_cases(char *type, va_list args, int counter, int i)
// {
// 	if (type[i] == 'd' || type[i] == 'i')
// 		temp = va_arg(args, int);
// 	else if (type[i] == 'u')
// 		temp = va_arg(args, unsigned int);
// 	else if (type[i] == 'c')
// 		temp = va_arg(args, int);
// 	else if (type[i] == 's')
// 		temp = va_arg(args, void *);
// 	else if (type[i] == 'p')
// 		temp = va_arg(args, void *);
// 	else if (type[i] == 'x')
// 		temp = va_arg(args, void *);
// 	else if (type[i] == 'X')
// 		temp = va_arg(args, void *);
// 	else if (type[i] == '%')
// 		temp = va_arg(args, int);
// 	return (1);
// }
