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

# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_printstr(char *str);
int		ft_printchar(int c);
int		ft_intdec(int n);
int		ft_unsigned(unsigned long long n);
int		ft_percent(int c);
int		ft_hex(unsigned int n, char up_low);
int		ft_formatspecifier(va_list args, const char format);
int		ft_voidpointer(uintptr_t p);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned long long n);

#endif
