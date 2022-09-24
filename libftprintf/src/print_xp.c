/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:33:01 by mpascual          #+#    #+#             */
/*   Updated: 2022/09/24 20:03:15 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		put_x(unsigned int nb, int len, bool mayus, t_var *var)
{
	if (var->is_precision && var->precision == 0)
		return (0);
	while (var->precision > len)
	{
		var->printed_chars += ft_putchar('0');
		var->precision--;
	}
	ft_itohex(nb, mayus, var);
	return (0);
}

void	print_x(unsigned int nb, bool mayus, t_var *var)
{
	int		len;
	int		pre_printed;

	len = (var->is_precision && !var->precision) ? 0 : ft_nbrlen(nb, 16);
	pre_printed = (var->precision > len) ? (var->precision - len) : 0;
	if (var->minus)
		put_x(nb, len, mayus, var);
	while (var->width > (len + pre_printed))
	{
		if (var->zero && !var->is_precision)
			var->printed_chars += ft_putchar('0');
		else
			var->printed_chars += ft_putchar(' ');
		var->width--;
	}
	if (var->minus == false)
		put_x(nb, len, mayus, var);
}

void	print_p(unsigned long nb, t_var *var)
{
	int		len;

	len = ft_nbrlen(nb, 16) + 2;
	if (var->minus)
	{
		var->printed_chars += ft_putstr("0x");
		ft_itohex(nb, false, var);
	}
	while (var->width > len)
	{
		if (var->zero && !var->is_precision)
			var->printed_chars += ft_putchar('0');
		else
			var->printed_chars += ft_putchar(' ');
		var->width--;
	}
	if (var->minus == false)
	{
		var->printed_chars += ft_putstr("0x");
		ft_itohex(nb, false, var);
	}
}
