/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:32:09 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 12:40:23 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + 48);
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long p)
{
	int		len_ptr;

	len_ptr = 0;
	len_ptr += write(1, "0x", 2);
	if (p == 0)
		len_ptr += write(1, "0", 1);
	else
	{
		ft_put_ptr(p);
		len_ptr += ft_ptr_len(p);
	}
	return (len_ptr);
}
