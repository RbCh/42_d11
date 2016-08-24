/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoy <rchoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:06:33 by rchoy             #+#    #+#             */
/*   Updated: 2016/08/23 11:35:23 by rchoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

void	print_yellow(void *str)
{
	ft_putstr(YEL "");
	ft_putstr(str);
	ft_putstr(RESET " ");
}

void	describe_action_with_data(char *str, void *data)
{
	ft_putstr(GRN "");
	ft_putstr(str);
	ft_putstr(RESET " with data \""GRN);
	if (data)
		ft_putstr(data);
	else
		ft_putstr("NULL");
	ft_putstr(RESET"\"");
}

int		main(int argc, char **argv)
{
	int i;
	t_list *element;
	char *data[20] = {"ohg", "L26qo", "irH8kw4K", "x7", "8xAUPWD", "Z", "wPKpd", "7RzJujHS", "K0nd6Fev", "bnMxacmLCA5e", "6OYt51", "eDnx8Kmg", "w728aBv", "6GNCrxlq", "gbt", "JHTrg8hCLt5", "ET9V0dAig", NULL, NULL, NULL};

	i = 0;
	while(i < 20)
	{
		ft_putstr("\n");
		ft_putnbr(i);
		describe_action_with_data(" Create first element of chained list", data[i]);
		element = ft_create_elem(data[i]);
		i++;
	}
}
