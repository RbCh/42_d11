/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoy <rchoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:06:33 by rchoy             #+#    #+#             */
/*   Updated: 2016/08/23 19:27:51 by rchoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

void	print_list(t_list *list)
{
	ft_putstr("\n\t[ " CYN);
	while (list)
	{
		ft_putstr(list->data);
		ft_putstr(" -> ");
		list = list->next;
	}
	ft_putstr("NULL");
	ft_putstr(RESET " ]\n");
}

void	describe_action_with_data(char *str, void *data)
{
	ft_putstr(GRN "");
	ft_putstr(str);
	ft_putstr(RESET " with data \""GRN);
	ft_putstr(data);
	ft_putstr(RESET"\" : ");
}

void	describe_action_no_data(char *str)
{
	ft_putstr(GRN "");
	ft_putstr(str);
	ft_putstr(RESET"");
}

void	try_function(char *str, void *data, t_list **element, void (*f)(t_list**, void*))
{
	ft_putstr(GRN "");
	ft_putstr(str);
	ft_putstr(RESET " with data \""GRN);
	ft_putstr(data);
	ft_putstr(RESET"\"");
	f(element, data);
	print_list(*element);
}

void	print_yellow(void *str)
{
	ft_putstr(YEL "");
	ft_putstr(str);
	ft_putstr(RESET " ");
}

int		main(int argc, char **argv)
{
	t_list	*element;
	t_list	*inputed_args;
	char *test_values[] = {"toto", "tata", "tati", "tutu", "OK"};

	describe_action_with_data("Create first element of chained list", test_values[0]);
	element = ft_create_elem("NULL");
	inputed_args = ft_list_push_params(argc, argv);
	print_list(element);
	try_function("Push back", test_values[1], &element, &ft_list_push_back);
	try_function("Push back", test_values[2], &element, &ft_list_push_back);
	try_function("Push back", test_values[3], &element, &ft_list_push_back);
	try_function("Push front", test_values[0], &element, &ft_list_push_front);
	try_function("Push front", test_values[2], &element, &ft_list_push_front);
	describe_action_no_data("Sort thus created list: ");
	ft_list_sort(&element, &ft_strcmp);
	print_list(element);
	describe_action_no_data("Result from command lines parameters : ");
	print_list(inputed_args);
	describe_action_no_data("Sort thus created list: ");
	ft_list_sort(&inputed_args, &ft_strcmp);
	print_list(inputed_args);
	describe_action_with_data("Result from ft_sorted_list_insert", "../a");
	ft_sorted_list_merge(&inputed_args, element, ft_strcmp);
	print_list(element);

}
