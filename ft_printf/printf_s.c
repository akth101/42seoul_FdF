/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:57:16 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/10 12:57:18 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_s(va_list ap)
{
	char	*s;
	int		cnt;

	s = va_arg(ap, void *);
	cnt = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s++, 1);
		cnt++;
	}
	return (cnt);
}
