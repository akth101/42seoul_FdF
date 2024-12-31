/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:53:01 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/14 18:53:02 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	calib_sign_i(long num, int *cnt)
{
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		*cnt += 1;
		return ((long)num);
	}
	return ((long)num);
}

static void	recursive_i(long num, int *cnt)
{
	char	temp;

	if (num == 0)
		return ;
	recursive_i(num / 10, cnt);
	temp = (char)((num % 10) + 48);
	*cnt += 1;
	write(1, &temp, 1);
}

int	printf_i(va_list ap)
{
	long	num;
	int		cnt;
	long	res;

	num = va_arg(ap, int);
	cnt = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	res = calib_sign_i(num, &cnt);
	recursive_i(res, &cnt);
	return (cnt);
}
