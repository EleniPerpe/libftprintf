/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:23:20 by eperperi          #+#    #+#             */
/*   Updated: 2024/03/23 14:04:42 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num(int n, int *counter)
{
	char	s;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*counter) += 11;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		(*counter)++;
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		(*counter)++;
		return ;
	}
	if (n > 9)
		print_num (n / 10, counter);
	s = n % 10 + 48;
	(*counter)++;
	write(1, &(s), 1);
}

void	print_unum(unsigned int n, int *counter)
{
	char	s;

	if (n == 0)
	{
		write(1, "0", 1);
		(*counter)++;
		return ;
	}
	if (n > 9)
		print_unum (n / 10, counter);
	s = n % 10 + 48;
	(*counter)++;
	if (write(1, &s, 1) < 0)
	{
		(*counter) = -1;
		return ;
	}
}

void	putstr(char *s, int *counter)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		(*counter) += 6;
		write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		if (write(1, &s[i], 1) < 0)
		{
			(*counter) = -1;
			return ;
		}
		i++;
		(*counter)++;
	}
}

void	print_char(int c, int *counter)
{
	if (write(1, &c, 1) < 0)
	{
		(*counter) = -1;
		return ;
	}
	(*counter)++;
}
