/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:05 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 12:40:50 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_len_nb(size_t nb)
{
	size_t		len_nb;
	long long	nbr;

	nbr = nb;
	len_nb = 0;
	if (nbr == 0)
		return (++len_nb);
	if (nbr < 0)
	{
		len_nb++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len_nb++;
	}
	return (len_nb);
}

char	*ft_pre_itoa(char *str, long long nbr, size_t i)
{	
	if (nbr == 0)
	{
		str[i] = nbr + 48;
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		i;
	long long	nbr;
	char		*str;

	nbr = n;
	i = ft_len_nb(nbr);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	str[i] = '\0';
	i--;
	return (ft_pre_itoa(str, nbr, i));
}
