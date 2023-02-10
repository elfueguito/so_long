/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:09:36 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/05 18:39:08 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}		

int	ft_printnbr(int n)
{
	int		len_num;
	char	*num;

	len_num = 0;
	num = ft_itoa(n);
	if (!num)
		return (-1);
	len_num = ft_printstr(num);
	free(num);
	return (len_num);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
