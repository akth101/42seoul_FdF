/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsprint_ts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:51:57 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/08 16:51:58 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	letsprint_ts(va_list ap, const char *str, int *cnt)
{
	if (*str != 'c' && *str != 's' && *str != 'p' && *str != 'd' && *str != 'i'
		&& *str != 'u' && *str != 'x' && *str != 'X')
		return (-1);
	if (*str == 'c')
		*cnt += printf_c(ap);
	if (*str == 's')
		*cnt += printf_s(ap);
	if (*str == 'p')
		*cnt += printf_p(ap);
	if (*str == 'd')
		*cnt += printf_d(ap);
	if (*str == 'i')
		*cnt += printf_i(ap);
	if (*str == 'u')
		*cnt += printf_u(ap);
	if (*str == 'x')
		*cnt += printf_lower_x(ap);
	if (*str == 'X')
		*cnt += printf_upper_x(ap);
	return (0);
}
