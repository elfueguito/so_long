/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:40:27 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 12:39:30 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_checkconv(va_list args, const char conv)
{
	if (conv == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (conv == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (conv == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long long)));
	else if (conv == 'd' || conv == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (conv == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (conv == 'X')
		return (ft_print_hex_unsigned_up(va_arg(args, unsigned int)));
	else if (conv == 'x')
		return (ft_print_hex_unsigned(va_arg(args, unsigned int)));
	else if (conv == '%')
		return (ft_print_percent());
	return (0);
}

int	handle_character(const char *str, va_list args, size_t *i)
{
	if (str[*i] == '%' && (str[*i + 1]))
		return (ft_checkconv(args, str[++(*i)]));
	return (ft_printchar(str[*i]));
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	size_t	len_result;
	int		result;

	i = 0;
	len_result = 0;
	va_start(args, str);
	if (write (1, 0, 0) != 0)
		return (-1);
	while (str[i])
	{
		result = handle_character(str, args, &i);
		if (result < 0)
			return (-1);
		len_result += result;
		i++;
	}
	return (va_end(args), len_result);
}
