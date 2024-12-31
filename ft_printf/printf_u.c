/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:21:25 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/14 19:21:26 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive_u(unsigned int num, int *cnt)
{
	char	temp;

	if (num == 0)
		return ;
	recursive_u(num / 10, cnt);
	temp = (char)((num % 10) + 48);
	*cnt += 1;
	write(1, &temp, 1);
}

int	printf_u(va_list ap)
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
	recursive_u(num, &cnt);
	return (cnt);
}
