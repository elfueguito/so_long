/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:54:52 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/05 14:29:39 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
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

char	*ft_uhexitoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_hex_len(n);
	num = malloc(sizeof(char) * len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (num != 0 && len > 0)
	{
		num[len - 1] = n % 16;
		if (num[len - 1] < 10)
		{
			num[len - 1] = 48 + num[len - 1];
			len--;
		}
		else
		{
			num[len - 1] = 87 + num[len - 1];
			len--;
		}
		n = n / 16;
	}
	return (num);
}

int	ft_print_hex_unsigned(unsigned int n)
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
		num = ft_uhexitoa(n);
		if (!num)
			return (-1);
		len_hex += ft_printstr(num);
		free(num);
	}
	return (len_hex);
}
