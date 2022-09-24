/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascual <mpascual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:29:35 by mpascual          #+#    #+#             */
/*   Updated: 2022/09/24 20:02:40 by mpascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			put_di(int nb, int len, t_var *var)
{
	if (var->is_precision && var->precision == 0)
		return (0);
	if (nb < 0)
	{
		var->printed_chars += ft_putchar('-');
		nb *= -1;
	}
	while (var->precision > len)
	{
		var->printed_chars += ft_putchar('0');
		var->precision--;
	}
	if (nb != -2147483648)
		ft_putnbr(nb, var);
	else
		var->printed_chars += write(1, "2147483648", 10);
	return (0);
}

void		di_width(int len, bool neg, t_var *var)
{
	while (var->width > len)
	{
		if (var->zero && !var->is_precision)
		{
			if (neg)
			{
				var->printed_chars += ft_putchar('-');
				neg = false;
				var->nb_neg = true;
			}
			var->printed_chars += ft_putchar('0');
		}
		else
			var->printed_chars += ft_putchar(' ');
		var->width--;
	}
}

void		print_di(int nb, t_var *var)
{
	int		len;
	int		pre_printed;
	bool	neg;

	len = (var->is_precision && !var->precision) ? 0 : ft_nbrlen(nb, 10);
	pre_printed = (var->precision > len) ? (var->precision - len) : 0;
	neg = (nb < 0) ? true : false;
	if (nb < 0)
		pre_printed++;
	if (var->minus)
		put_di(nb, len, var);
	di_width((len + pre_printed), neg, var);
	nb *= var->nb_neg ? -1 : 1;
	if (var->minus == false)
		put_di(nb, len, var);
}
