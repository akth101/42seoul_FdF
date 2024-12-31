/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_upper_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:48:23 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/14 19:48:24 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive_upper_x(unsigned int p, int *cnt)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (p == 0)
		return ;
	recursive_upper_x(p / 16, cnt);
	*cnt += 1;
	write(1, &hexa[p % 16], 1);
}

int	printf_upper_x(va_list ap)
{
	unsigned int	num;
	int				cnt;

	num = va_arg(ap, unsigned int);
	cnt = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	recursive_upper_x(num, &cnt);
	return (cnt);
}
