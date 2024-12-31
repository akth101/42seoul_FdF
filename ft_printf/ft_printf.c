/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:04:25 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/08 16:04:26 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstr(const char **str, int *cnt)
{
	write(1, *str, 1);
	*str += 1;
	*cnt += 1;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	int		res;

	va_start(ap, str);
	cnt = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			printf_percent(&cnt);
			str += 2;
		}
		else if (*str == '%' && *(str + 1) != '%')
		{
			res = letsprint_ts(ap, (str + 1), &cnt);
			if (res == -1)
				return (-1);
			str += 2;
		}
		else
			putstr(&str, &cnt);
	}
	va_end(ap);
	return (cnt);
}
