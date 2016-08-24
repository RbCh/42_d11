/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoy <rchoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:04:08 by rchoy             #+#    #+#             */
/*   Updated: 2016/08/11 11:54:23 by rchoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putnbr(int n)
{
	unsigned int power;
	unsigned int digit_to_print;
	unsigned int positive_nbr;

	power = 1;
	if (n < 0)
		ft_putchar('-');
	positive_nbr = (n < 0) ? -n : n;
	while (positive_nbr / power > 9 )
		power = power * 10;
	while (power >= 1)
	{
		digit_to_print = positive_nbr / power;
		ft_putchar(digit_to_print + 48);
		positive_nbr = positive_nbr - (digit_to_print * power);
		power = power / 10;
	}
}
