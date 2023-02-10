/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:11:01 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/05 14:11:21 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int num)
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
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_num_len(n);
	num = malloc(sizeof(char) * len + 1);
	if (!num)
	{
		free(num);
		return (NULL);
	}
	num[len] = '\0';
	if (num == 0)
	{
		num[len - 1] = '0';
		return (num);
	}
	while (num != 0 && len > 0)
	{
		num[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len_num;
	char	*num;

	len_num = 0;
	if (n == 0)
	{
		write (1, "0", 1);
		len_num++;
	}
	else
	{
		num = ft_uitoa(n);
		if (!num)
			return (-1);
		len_num += ft_printstr(num);
		free(num);
	}
	return (len_num);
}
