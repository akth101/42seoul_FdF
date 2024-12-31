/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:05:25 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/08 16:05:26 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	putstr(const char **str, int *cnt);
int		letsprint_ts(va_list ap, const char *str, int *cnt);
void	letsgo_ap_next(va_list ap, char *str);
int		printf_c(va_list ap);
int		printf_s(va_list ap);
int		printf_p(va_list ap);
int		printf_d(va_list ap);
int		printf_i(va_list ap);
int		printf_u(va_list ap);
int		printf_lower_x(va_list ap);
int		printf_upper_x(va_list ap);
void	printf_percent(int *cnt);

#endif
