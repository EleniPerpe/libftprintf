/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_p_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:33:44 by eperperi          #+#    #+#             */
/*   Updated: 2024/03/23 13:33:34 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void print_p(char *res, int hex_len);
// int	check_null_p(unsigned long n);

char	*p_calc(unsigned long n, int *counter)
{
	char	*res;
	int		hex_len;
	int		temp;

	
	hex_len = check_null_p(n);
	temp = hex_len;
	res = malloc(hex_len + 3 * sizeof(char));
	(*counter) += 2;
	if (!res)
		return (NULL);
	while (--hex_len >= 0)
	{
		if (n % 16 > 9)
			res[hex_len + 2] = ((n % 16) + 87);
		else
			res[hex_len + 2] = ((n % 16) + 48);
		(*counter)++;
		n = n / 16;
	}
	print_p(res, temp);
	return (res);
}

void print_p(char *res, int hex_len)
{
	char *res_adrress;

	res[0] = '0';
	res[1] = 'x';
	res[hex_len + 2] = '\0';
	res_adrress = res;
	while (*res)
	{
		write(1, res, 1);
		res++;
	}
	free (res_adrress);
}

int	check_null_p(unsigned long n)
{
	int	hex_len;

	hex_len = 0;
	if (n == 0)
		hex_len = 1;
	else
	{
		while (n > 0)
		{
			n /= 16;
			hex_len++;
		}
	}
	return (hex_len);
}
