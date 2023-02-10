/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:58:27 by cbacquet          #+#    #+#             */
/*   Updated: 2022/12/06 12:44:41 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(int c);
int		ft_printstr(char *s);
int		ft_printnbr(int n);
int		ft_print_ptr(unsigned long long p);
int		ft_print_unsigned(unsigned int n);
int		ft_print_percent(void);
int		ft_print_hex_unsigned_up(unsigned int n);
int		ft_print_hex_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n);
int		ft_checkconv(va_list args, const char conv);
size_t	ft_len_nb(size_t nb);
int		ft_num_len(unsigned int num);
int		ft_hex_len(unsigned int num);
int		ft_hex_up_len(unsigned int num);
int		ft_ptr_len(uintptr_t n);
char	*ft_itoa(int n);
char	*ft_pre_itoa(char *str, long long nbr, size_t i);
char	*ft_utioa(unsigned int n);
char	*ft_uhexitoa(unsigned int n);
char	*ft_uhexupitoa(unsigned int n);
void	ft_putstr(char *s);
void	ft_put_ptr(uintptr_t n);
void	ft_putchar(char c);

#endif