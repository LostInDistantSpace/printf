/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:52:42 by bmouhib           #+#    #+#             */
/*   Updated: 2024/06/12 16:50:28 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned int nb, t_flag flag, int *count)
{
	int		len;
	int		to_pad;
	char	fill;
	char	*num;

	len = 0;
	fill = ' ';
	if (flag.zero && !flag.left && flag.precision < 0)
		fill = '0';
	num = ft_utoa(nb);
	to_pad = ft_pad_math(flag, num, nb);
	if (nb < 0 || flag.sign || flag.space)
		to_pad--;
	if (!flag.left)
		ft_print_padding(to_pad, fill, count);
	if (flag.precision - ft_strlen(num) > 0)
		ft_print_padding(flag.precision - ft_strlen(num), '0', count);
	if (nb || flag.precision)
		ft_print_s(num, count);
	if (flag.left)
		ft_print_padding(to_pad, fill, count);
	free(num);
}
