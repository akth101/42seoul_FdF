/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:58:15 by seongjko          #+#    #+#             */
/*   Updated: 2023/04/10 13:58:17 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive_p(unsigned long long p, int *cnt)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (p == 0)
		return ;
	recursive_p(p / 16, cnt);
	write(1, &hexa[p % 16], 1);
	*cnt += 1;
}

int	printf_p(va_list ap)
{
	void				*s;
	unsigned long long	a;
	int					cnt;

	s = va_arg(ap, void *);
	a = (unsigned long long)s;
	cnt = 0;
	write(1, "0x", 2);
	if (a == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	recursive_p(a, &cnt);
	return (cnt + 2);
}
