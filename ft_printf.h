/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:40:11 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/05 10:40:15 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *format, ...);
int	ft_printstr(char *str);
int	ft_printchar(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
static int	num_digits(int n);
static char	*ft_conditions(char *str, int n);
char	*ft_itoa(int n);
int	ft_intdec(int n);
static int	ft_itoa_unsigned_num_digits(int n);
static char	*ft_itoa_unsigned_conditions(char *str, int n);
char	*ft_unsigned_itoa(int n);
int	ft_unsigned(unsigned int n);
int	ft_percent(int c);
int	ft_hex(int n, char up_low);
int	ft_formatspecifier(va_list args, const char format);


#endif
