/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoy <rchoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 17:15:47 by rchoy             #+#    #+#             */
/*   Updated: 2016/08/18 19:24:56 by rchoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}