/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:04:12 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 12:40:39 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_up_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		len++;
		return (len);
	}
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

char	*ft_uhexupitoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_hex_len(n);
	num = malloc(sizeof(char) * len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n > 0 && len > 0)
	{
		num[len - 1] = n % 16;
		if (num[len - 1] < 10)
		{
			num[len - 1] = 48 + num[len - 1];
			len--;
		}
		else
		{
			num[len - 1] = 55 + num[len - 1];
			len--;
		}
		n = n / 16;
	}
	return (num);
}

int	ft_print_hex_unsigned_up(unsigned int n)
{
	int		len_hex;
	char	*num;

	len_hex = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		len_hex++;
	}
	else
	{
		num = ft_uhexupitoa(n);
		if (!num)
			return (-1);
		len_hex += ft_printstr(num);
		free(num);
	}
	return (len_hex);
}
